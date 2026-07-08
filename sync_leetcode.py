#!/usr/bin/env python3
"""Pull accepted LeetCode submissions, save them by topic, push to git.

Auth: LeetCode has no public API. We reuse your logged-in browser session by
reading the LEETCODE_SESSION and csrftoken cookies from env. Get them from
DevTools > Application > Cookies on leetcode.com (or copy from Network tab).

    export LEETCODE_SESSION=...       # the long JWT-looking cookie
    export LEETCODE_CSRF=...          # the csrftoken cookie
    python sync_leetcode.py

Re-run any time. It only writes/commits problems that are new or changed.
"""
import os
import re
import subprocess
import sys
import time

import requests

SESSION = os.environ.get("LEETCODE_SESSION")
CSRF = os.environ.get("LEETCODE_CSRF")
BASE = "https://leetcode.com"
ROOT = os.path.dirname(os.path.abspath(__file__))

# lang name from the API -> file extension
EXT = {
    "python": "py", "python3": "py", "cpp": "cpp", "c": "c", "java": "java",
    "javascript": "js", "typescript": "ts", "csharp": "cs", "go": "go",
    "kotlin": "kt", "swift": "swift", "rust": "rs", "ruby": "rb", "scala": "scala",
    "php": "php", "racket": "rkt", "erlang": "erl", "elixir": "ex", "dart": "dart",
    "mysql": "sql", "mssql": "sql", "oraclesql": "sql", "postgresql": "sql",
}


def slugify(s):
    return re.sub(r"[^a-z0-9]+", "-", s.lower()).strip("-")


def session():
    if not SESSION or not CSRF:
        sys.exit("Set LEETCODE_SESSION and LEETCODE_CSRF env vars (see file header).")
    s = requests.Session()
    s.cookies.set("LEETCODE_SESSION", SESSION, domain="leetcode.com")
    s.cookies.set("csrftoken", CSRF, domain="leetcode.com")
    s.headers.update({
        "x-csrftoken": CSRF,
        "referer": BASE,
        "user-agent": "Mozilla/5.0 leetcode-sync",
    })
    return s


def all_submissions(s):
    """Yield the newest accepted submission (with code) per problem."""
    seen = set()
    offset = 0
    while True:
        r = s.get(f"{BASE}/api/submissions/", params={"offset": offset, "limit": 20})
        r.raise_for_status()
        data = r.json()
        for sub in data["submissions_dump"]:
            if sub["status_display"] != "Accepted":
                continue
            slug = sub["title_slug"]
            if slug in seen:  # dump is newest-first, so first hit is latest AC
                continue
            seen.add(slug)
            yield sub
        if not data.get("has_next"):
            break
        offset += 20
        time.sleep(0.5)  # ponytail: fixed delay; add backoff only if you hit 429s


def topic_of(s, slug):
    """First topic tag, or 'uncategorized'. One GraphQL call per problem."""
    q = """query t($slug:String!){question(titleSlug:$slug){topicTags{slug}}}"""
    r = s.post(f"{BASE}/graphql", json={"query": q, "variables": {"slug": slug}})
    tags = r.json()["data"]["question"]["topicTags"]
    return tags[0]["slug"] if tags else "uncategorized"


def main():
    s = session()
    wrote = 0
    for sub in all_submissions(s):
        slug = sub["title_slug"]
        ext = EXT.get(sub["lang"], "txt")
        topic = topic_of(s, slug)
        path = os.path.join(ROOT, topic, f"{slugify(sub['title'])}.{ext}")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        header = f"# {sub['title']}\n# {BASE}/problems/{slug}/\n\n"
        body = header + sub["code"] if ext in ("py", "sql", "rb") else sub["code"]
        if os.path.exists(path) and open(path, encoding="utf-8").read() == body:
            continue  # unchanged, skip
        with open(path, "w", encoding="utf-8") as f:
            f.write(body)
        wrote += 1
        print(f"  {topic}/{os.path.basename(path)}")
        time.sleep(0.3)

    if wrote == 0:
        print("Nothing new.")
        return
    subprocess.run(["git", "add", "-A"], cwd=ROOT, check=True)
    subprocess.run(["git", "commit", "-m", f"leetcode: sync {wrote} solution(s)"],
                   cwd=ROOT, check=True)
    subprocess.run(["git", "push"], cwd=ROOT, check=True)
    print(f"Pushed {wrote} solution(s).")


if __name__ == "__main__":
    main()
