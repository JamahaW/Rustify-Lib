#pragma once

namespace rs {

/// Результат операции
template<typename T, typename E> struct Result {

private:

    bool is_ok;

public:

    union {
        T value;
        E error;
    };

    /// Успешный результат
    Result(T val) :
        is_ok{true}, value{val} {}


    /// Результат с ошибкой
    Result(E err) :
        is_ok{false}, error{err} {}

    /// Проверка на успех
    bool ok() const { return is_ok; }

    /// Проверка на ошибку
    bool fail() const { return not is_ok; }
};

// Специализация для void
template<typename E> struct Result<void, E> {
    bool is_ok;
    E error;

    /// Успешный результат
    Result() :
        is_ok{true} {}

    /// Результат с ошибкой
    Result(E err) :
        is_ok{false}, error{err} {}

    bool ok() const { return is_ok; }

    bool fail() const { return not is_ok; }
};

} // namespace rs