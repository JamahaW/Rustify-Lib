#pragma once

namespace rs {

/// Аналог Rust Option
template<typename T> struct Option {

private:

    bool is_some;

public:

    T value;

    /// Некоторые значение
    Option(T val) :
        is_some{true}, value{val} {}

    /// Отсутствие значения
    Option() :
        is_some{false}, value{T{}} {}

    /// Проверка наличия значения
    bool some() const { return is_some; }

    /// Проверка отсутствия значения
    bool none() const { return !is_some; }
};

} // namespace rs