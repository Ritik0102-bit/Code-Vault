Markdown (.md) This is the best format if you are keeping a separate notes file. VS Code renders this beautifully (Press Ctrl+Shift+V to preview it after pasting).

# Data Structures: Stacks and Expressions

## 1. Understanding Infix, Postfix, and Prefix Expressions
This refers to the three different ways we can write mathematical expressions.

* **Infix:** The operator is between operands. This is how humans write math.
    * *Example:* `A + B`
* **Prefix (Polish Notation):** The operator comes **before** the operands.
    * *Example:* `+ A B`
* **Postfix (Reverse Polish Notation):** The operator comes **after** the operands.
    * *Example:* `A B +`

**Why do we need them?**
Computers find Infix hard to parse because of "order of operations" (BODMAS/PEMDAS) and brackets. Prefix and Postfix are easier for machines because the order of execution is linear and doesn't require brackets.

---

## 2. Evaluation of Infix Expressions
Since computers struggle with Infix, evaluating them directly requires **two stacks**:
1.  **Operand Stack:** Stores numbers (e.g., 2, 5).
2.  **Operator Stack:** Stores symbols (e.g., +, *).

**Process:**
* Iterate through the expression.
* If you see a **number**, push it.
* If you see an **operator**, check precedence (is `*` stronger than `+`?) and pop simpler operators to calculate them first before pushing the new one.

---

## 3. Evaluation of Postfix Expressions
This is the easiest for computers and is widely used. You only need **one stack**.

**Process:**
1.  Scan the expression from **left to right**.
2.  If you see a **number**, push it onto the stack.
3.  If you see an **operator** (e.g., `+`), pop the top two numbers, add them, and push the result back.
4.  The final answer remains on the stack.

*Example:* `2 3 +`
* Push 2, Push 3.
* See `+`. Pop 3 & 2.
* Calculate `2 + 3 = 5`.
* Push 5.

---

## 4. Evaluation of Prefix Expressions
This is very similar to Postfix, but you scan from **right to left**.

**Process:**
1.  Scan the expression from **right to left**.
2.  If you see a **number**, push it onto the stack.
3.  If you see an **operator**, pop the top two numbers, calculate, and push the result.

*Note:* Because we are scanning backwards, the first number popped is the first operand (unlike postfix where the first popped is the second operand).

---

## 5. Conversion of Prefix to Postfix
This involves changing the format from `+ A B` to `A B +`.

**Algorithm:**
1.  Read the prefix expression in **reverse** (right to left).
2.  If the symbol is an **operand**, push it to a stack.
3.  If the symbol is an **operator**, pop two strings from the stack, combine them as `(operand1 + operand2 + operator)`, and push the new string back.

---

## 6. Conversion of Infix to Postfix (Shunting Yard Algorithm)
This algorithm converts human-readable math (`A + B`) into machine-readable math (`A B +`).

**Algorithm:**
1.  Scan **left to right**.
2.  Print **operands** (numbers/letters) immediately to the output.
3.  Push **operators** (`+`, `-`, `*`) onto a stack.
4.  If the incoming operator has **lower precedence** than the one on top of the stack, pop the stack and print the operator first.
5.  If you see `(`, push it. If you see `)`, pop everything until you find the matching `(`.