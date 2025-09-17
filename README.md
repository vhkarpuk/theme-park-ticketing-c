# 🎢 Theme Park Ticketing System (C Project)

![C](https://img.shields.io/badge/language-C-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![Last Commit](https://img.shields.io/github/last-commit/vhkarpuk/theme-park-ticketing-c)

A **menu-driven ticketing system in C** that calculates entry costs for visitors to a theme park.  
Developed to practice **conditionals, switch/case, and user input validation**.

## Features
- Menu flow: **Book Tickets**, **View Ticket Prices**, **Exit**
- Validated inputs:
  - Ride: `T` (Thrill), `W` (Water), `F` (Family)
  - Ticket: `S` (Standard), `F` (Fast Pass)
  - Quantity: integer `> 0`
  - Meal package: `y/n` (case-insensitive)
- Pricing via nested `switch`
- **Bulk discount:** 15% when quantity > 5
- **Meal add-on:** £6.50 per ticket
- Clear, formatted summary (subtotal, discount, meal cost, final total)

## Price Table
| Ride   | Standard | Fast Pass |
|--------|----------|-----------|
| Thrill | £20.00   | £30.00    |
| Water  | £18.00   | £28.00    |
| Family | £15.00   | £25.00    |

## Build & Run

### Windows (MinGW-w64 / GCC)
```bash
gcc src/theme_park_menu.c -o theme_park_menu.exe
./theme_park_menu.exe
