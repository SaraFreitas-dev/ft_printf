*This project has been created as part of the 42 curriculum by sarfreit.*

# Description

**ft_printf** is a 42 project that recreates part of the behavior of the standard `printf()` function.  
It strengthens your skills in:
- handling variadic arguments (`va_list`)
- manual data formatting
- modular and clean C programming
- implementing flags and reproducing standard printf behavior

---

## 🧠 Objective

Implement the function:
```c
int ft_printf(const char *format, ...);
```

This function:
- Prints formatted output to stdout
- Supports several conversion specifiers
- Returns the number of characters printed
- Reproduces the behavior of the original printf for mandatory conversions

---

## 🎨 Mandatory Part

### ✔ Implemented conversions

| Specifier | Meaning | Example |
|-----------|---------|---------|
| `%c` | Character | `'A'` |
| `%s` | String | `"Hello"` |
| `%p` | Pointer (`0x...`) or `(nil)` | `(nil)` |
| `%d` | Signed integer | `-42` |
| `%i` | Signed integer | `24` |
| `%u` | Unsigned integer | `42` |
| `%x` | Hexadecimal (lowercase) | `2a` |
| `%X` | Hexadecimal (uppercase) | `2A` |
| `%%` | Prints `%` | `%` |

### ✔ General rules

- Only `write()` may be used for printing
- Return value = total printed characters
- `%p` prints `(nil)` when the pointer is NULL
- Code must follow the 42 Norm

---

## ⭐ Bonus Part

This project implements the bonus flag set allowed by the subject:

### ✔ Supported flags

| Flag | Description | Example | Output |
|------|-------------|---------|--------|
| `+` | Always show the sign | `%+d, 42` | `+42` |
| ` ` (space) | Leading space for positive numbers | `% d, 42` | ` 42` |
| `#` | Hexadecimal prefix | `%#x, 255` | `0xff` |

### ✔ Flag rules

- If `+` and ` ` are both used → `+` wins
- `#` only affects `%x` and `%X`
- `#` does not add prefix when the number is 0

Other flags such as width, precision, `-`, `0`, and `*` are not implemented.


## 🔍 How It Works

1. `ft_printf` iterates through the format string
2. When it finds `%`, it checks:
   - flags
   - conversion type
3. It calls helper functions depending on the type
4. It prints numbers, strings, characters, hex, and pointers manually
5. It returns the number of characters printed

---

## Instructions

1. **Preparation (Compiling `libftprintf.a`):**
    ```bash
    make all
    ```

2. **Compilation and Linking:**
    ```bash
    # Link main_mandatory.c against libftprintf.a and libft.a
    cc -Wall -Wextra -Werror main_mandatory.c libftprintf.a -I . -L libft -lft -o test_mandatory
    ```

3. **Execution:**
    ```bash
    ./test_mandatory
    ```

1. **Preparation (Compiling `libftprintf.a` with Bonus features):**
    ```bash
    make bonus
    ```

2. **Compilation and Linking:**
    ```bash
    # Link main_bonus.c against the bonus libftprintf.a and libft.a
    cc -Wall -Wextra -Werror main_bonus.c libftprintf.a -I . -L libft -lft -o test_bonus
    ```

3. **Execution:**
    ```bash
    ./test_bonus
    ```

Check for memory leaks:
```bash
valgrind --leak-check=full ./test_mandatory
valgrind --leak-check=full ./test_bonus
```

Clean the project:
```bash
make clean
make fclean
make re
```

---

## Resources

For this project I used the help of some GitBooks from older students, and websites like GeeksforGeeks and W3Schools.
