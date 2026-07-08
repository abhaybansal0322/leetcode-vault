# 🚀 leetcode-vault

Auto-synced LeetCode solutions, organized by topic. Solve → Accepted → pushed to GitHub, hands-free.

Every accepted submission is pulled straight from LeetCode and saved into a folder for
**each** of its topic tags (so a two-pointer array problem lands in both `array/` and
`two-pointers/`). A GitHub Action re-runs the sync on a schedule, so the repo keeps itself
up to date without me lifting a finger.

## How it works

[`sync_leetcode.py`](sync_leetcode.py) uses my logged-in LeetCode session (via cookies) to
fetch every accepted submission with its code, then commits and pushes anything new.

```bash
pip install requests
export LEETCODE_SESSION=...   # PowerShell: $env:LEETCODE_SESSION="..."
export LEETCODE_CSRF=...      # PowerShell: $env:LEETCODE_CSRF="..."
python sync_leetcode.py
```

## Automation

[`.github/workflows/sync.yml`](.github/workflows/sync.yml) runs the script hourly on GitHub's
servers. The two cookies live in repo **Settings → Secrets and variables → Actions**. The
`LEETCODE_SESSION` cookie expires every few weeks — when the Action fails on auth, refresh
that one secret.
