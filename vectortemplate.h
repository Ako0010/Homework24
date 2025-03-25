#pragma once

template <typename T>
class Vector {
private:
    T* _array = nullptr;
    size_t _size = 0;
    size_t _capacity = 15;

public:
    Vector() {
        _array = new T[_capacity];
    }

    Vector(size_t capacity) : _capacity(capacity) {
        _array = new T[_capacity];
    }

    ~Vector() {
        delete[] _array;
    }

    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    T* getData() const { return _array; }

    T& operator[](const size_t& index) {
        return _array[index];
    }

    void operator()() const {
        for (size_t i = 0; i < _size; i++)
            cout << _array[i] << ' ';
        cout << endl;
    }

    void push_back(const T& value) {
        if (_size < _capacity) {
            _array[_size++] = value;
            return;
        }

        _capacity *= 2;
        T* temp = new T[_capacity];

        for (size_t i = 0; i < _size; i++)
            temp[i] = _array[i];

        temp[_size++] = value;

        delete[] _array;
        _array = temp;
    }

    void push_front(const T& value) {
        if (_size < _capacity) {
            for (size_t i = _size; i > 0; --i) {
                _array[i] = _array[i - 1];
            }
            _array[0] = value;
            ++_size;
            return;
        }

        _capacity *= 2;
        T* temp = new T[_capacity];

        temp[0] = value;

        for (size_t i = 0; i < _size; i++) {
            temp[i + 1] = _array[i];
        }

        delete[] _array;
        _array = temp;

        ++_size;
    }

    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    void pop_front() {
        if (_size > 0) {
            for (size_t i = 0; i < _size - 1; ++i) {
                _array[i] = _array[i + 1];
            }
            --_size;
        }
    }

    void insert_by_index(size_t index, const T& value) {
        if (index > _size) return;
        if (_size == _capacity) {
            _capacity *= 2;
            T* temp = new T[_capacity];
            for (size_t i = 0; i < index; ++i) {
                temp[i] = _array[i];
            }
            temp[index] = value;
            for (size_t i = index; i < _size; ++i) {
                temp[i + 1] = _array[i];
            }
            delete[] _array;
            _array = temp;
        }
        else {
            for (size_t i = _size; i > index; --i) {
                _array[i] = _array[i - 1];
            }
            _array[index] = value;
        }
        ++_size;
    }

    void delete_by_index(size_t index) {
        if (index >= _size) return;
        for (size_t i = index; i < _size - 1; ++i) {
            _array[i] = _array[i + 1];
        }
        --_size;
    }

    size_t find(const T& value) const {
        for (size_t i = 0; i < _size; ++i) {
            if (_array[i] == value) {
                return i;
            }
        }
        return numeric_limits<size_t>::max();
    }

    size_t rfind(const T& value) const {
        for (size_t i = _size; i > 0; --i) {
            if (_array[i - 1] == value) {
                return i - 1;
            }
        }
        return numeric_limits<size_t>::max();
    }

    void sort(bool reverse = false) {
        for (size_t i = 0; i < _size - 1; ++i) {
            for (size_t j = 0; j < _size - i - 1; ++j) {
                if ((reverse && _array[j] < _array[j + 1]) || (!reverse && _array[j] > _array[j + 1])) {
                    T temp = _array[j];
                    _array[j] = _array[j + 1];
                    _array[j + 1] = temp;
                }
            }
        }
    }
};