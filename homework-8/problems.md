---
title: "Computer Information Systems 23 - Homework 8"
author: Cody Vig
output:
  pdf_document:
    toc: yes
    toc_depth: 3
---

# Problem 1

*(20 points)* Suppose that stack is a object of type `linkedStackType<int>`. What is the difference between the statements `stack.top();` and `stack.pop();`?

## Solution

`stack.top()` would return the last element in the stack without editing the stack itself. `stack.pop()` removes the last element from the stack all together.

---
