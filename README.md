# Rustify-Lib

Rust-подобные утилиты для безопасного embedded C++

## Основные возможности

- Примитивы: `rs::u8`, `rs::i32`, `rs::usize`, etc

- Обработка ошибок: `rs::Result<E>`

- Форматирование строк: `rs::ArrayString<N>`

- Header-only реализация, нулевые аллокации

## Быстрый старт

Добавьте в platformio.ini:

```ini
lib_deps = 
    https://github.com/JamahaW/Rustify-Lib.git
```

## Пример:

```cpp
#include <rs/primitives.hpp>
#include <rs/Result.hpp>
#include <rs/ArrayString.hpp>

enum class Setup : rs::u8 {Ok = 0, DriverFail, NetFail, LowBattery};

rs::Result<MyError> setupDevice() {
    if (/* Driver Fail */) return {Setup::DriverFail};
    if (/* Net Fail */) return {Setup::NetFail};
    if (/* LowBattery */) return {Setup::LowBattery};
    
    return {Setup::Ok};
}

auto setupDevice result = setupDevice();

auto msg = rs::formatted<32>("Status: %d", result.ok());
```

## Лицензия
MIT License - подробнее см. [LICENSE](LICENSE)