# Rustify

Rust-подобные утилиты для безопасного embedded C++

## Основные возможности

- Короткие и лаконичные псевдонимы: `rs::u8`, `rs::i32`, `rs::size` и другие
- Обработка ошибок: `rs::Result<T, E>` и `rs::Result<void, E>`
- Опциональные значения: `rs::Option<T>`
- Форматирование строк: `rs::ArrayString<N>` и `rs::formatted<N>()`
- Header-only реализация
- Нулевые аллокации
- Совместимость с C++11 и выше

## Быстрый старт

Добавьте в platformio.ini:

```ini
lib_deps =
    https://github.com/KiraFlux/Rustify.git
```

# Примеры использования

---

## Работа с Result

```cpp
#include <rs/Result.hpp>
#include <rs/primitives.hpp>

enum class SetupError {
    DriverFail, 
    NetFail, 
    LowBattery 
};

// Функция с возвратом результата
rs::Result<rs::u32, SetupError> calculateValue() {
    if (/* ошибка */) return {SetupError::DriverFail};
    return {42}; // Успешное значение
}

// Специализация для void
rs::Result<void, SetupError> setupDevice() {
    if (/* ошибка */) return {SetupError::NetFail};
    return {}; // Успех
}

void setup() {
    auto result = calculateValue();
    if (result.ok()) {
        rs::u32 value = result.value;
        // Используем значение
    }
    
    auto deviceResult = setupDevice();
    if (deviceResult.fail()) {
        SetupError err = deviceResult.error;
        // Обработка ошибки
    }
}
```

---

## Работа с Option

```cpp
#include <rs/Option.hpp>

rs::Option<rs::i32> parseNumber(const char* str) {
    // Логика парсинга...
    if (valid) return {42};
    return {}; // None
}

void setup() {
    auto num = parseNumber("123");
    if (num.some()) {
        rs::i32 value = num.value;
        // Используем значение
    }
}
```

---

## Форматирование строк

```cpp
#include <rs/ArrayString.hpp>

void setup() {
    auto msg = rs::formatted<32>("Temperature: %d°C", 25);
    
    // msg - это std::array<char, 32>
    // Использование как C-строки:
    uart_send(msg.data());
    
    // Или напрямую:
    Serial.printf("My msg: %s\n", msg.data());
}
```

## Преимущества

- Нулевые накладные расходы - все операции выполняются на стеке
- Простота интеграции - header-only решение
- Совместимость - работает с любыми платформами
- Предикативные методы - `.ok()`, `.fail()`, `.some()`, `.none()`

---

## Лицензия

MIT License - подробнее см. [LICENSE](LICENSE)