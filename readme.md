# 🧵 ft_printf

**ft_printf** is a 42 project that recreates part of the behavior of the standard `printf()` function from libc.  
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

**According to the subject:**
> You only need to implement one bonus set.  
> This project implements: `#`, `+`, and space.

---

## 📁 Project Structure

```
ft_printf/
├── ft_printf.c
├── ft_printf.h
├── ft_printf_utils.c
├── ft_flags_bonus.c
├── libft/
│   ├── *.c
│   └── libft.a
└── Makefile
```

---

## 🔍 How It Works

1. `ft_printf` iterates through the format string
2. When it finds `%`, it checks:
   - flags
   - conversion type
3. It calls helper functions depending on the type
4. It prints numbers, strings, characters, hex, and pointers manually
5. It returns the number of characters printed

---

## ⚙️ Compilation

Build the library:
```bash
make
```

Use it in your program:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -I .
```

---

## 🧪 Example Usage

```c
int main(void)
{
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Pointer: %p\n", NULL);
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Unsigned: %u\n", 4242);
    ft_printf("Hex: %x / %X\n", 255, 255);
    ft_printf("Percent: %%\n");
    
    // Bonus flags
    ft_printf("Plus flag: %+d\n", 42);
    ft_printf("Space flag: % d\n", 42);
    ft_printf("Hash flag: %#x\n", 255);
    
    return (0);
}
```

---

## 🧾 Notes

- Fully compliant with the 42 Norm
- No forbidden functions
- Bonus is evaluated only if mandatory part is perfect
- `%p` must print `(nil)` for null pointers
- Every printed character must be counted precisely

---

## 📜 License

This project is part of the 42 curriculum.  
You may read and study the code — just make sure you truly understand it. ✨