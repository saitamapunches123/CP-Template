# replit.md

## Overview

This is a **Competitive Programming (CP) reference repository** — a collection of cheat sheets, notes, and theoretical summaries covering key topics used in competitive programming contests. It is not a runnable application; it's a knowledge base written in Markdown files organized by topic (number theory, combinatorics, segment trees, dynamic programming, bit operations, etc.). The goal is to serve as a quick-reference guide during practice and contests.

## User Preferences

Preferred communication style: Simple, everyday language.

## System Architecture

This repository has no application code, build system, or runtime. It is purely a documentation/reference project.

### Directory Structure

- **Root level**: General cheat sheets (time/space complexity, powers of 2 vs 10)
- **Bit Operations/**: Notes on bitwise operation patterns and tricks
- **Combinatorics/**: Formulas for nCr, nPr, stars and bars, inclusion-exclusion
- **DP/**: Dynamic programming patterns, specifically probability/expectation DP
- **Number Theory/**: Modular arithmetic, mod inverse, GCD/LCM properties, Bézout's theorem, Fermat's theorem
- **Segment Trees/**: Lazy segment tree invariants and implementation notes
- **.vscode/**: Editor settings for C++ file associations

### Design Decisions

- **Markdown-only format**: All content is in `.md` files for easy reading on GitHub, VS Code, or any Markdown viewer. No code execution needed.
- **Topic-based folder organization**: Each major CP topic gets its own folder, making it easy to find relevant notes.
- **Linked to real problems**: Many notes include links to Codeforces/AtCoder problems as examples, tying theory to practice.
- **C++ focus**: The `.vscode/settings.json` and references throughout suggest the user primarily codes in C++.

### If Extending This Project

If this project were to be extended into an interactive tool or web app:
- Consider a simple static site generator (e.g., MkDocs, Docusaurus) to make the notes browsable
- Keep the Markdown source of truth; any app layer should render from these files
- No database is needed unless adding user-specific features like bookmarks or progress tracking

## External Dependencies

This project has **no external dependencies** — no packages, no APIs, no databases, no third-party services. It is a standalone collection of Markdown documentation files. The only tooling reference is a VS Code settings file for C++ file associations.