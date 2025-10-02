#include "func.hpp"
#include <string>

Four::Four() : arraySize(0), dataArray(nullptr) {}

Four::Four(unsigned int t) {
  arraySize = 0;
  if (t != 0) {
    unsigned char buf[4096];
    unsigned char digit{};
    
    do {
      digit = static_cast<unsigned char>(t % 10);
      if (digit >= 4) {
        throw std::invalid_argument("В четверичной СС допустимы только цифры от 0 до 3");
      }
      buf[arraySize++] = digit;
      t /= 10;
    } while (t > 0);
    
    dataArray = new unsigned char[arraySize];
    for (size_t i = 0; i < arraySize; ++i) {
      dataArray[i] = buf[i];
    }
  } else {
    dataArray = nullptr;
  }
}

Four::Four(const std::initializer_list<unsigned char> &vals) {
  arraySize = vals.size();
  dataArray = new unsigned char[arraySize];

  size_t index = arraySize - 1;
  for (const auto &value : vals) {
    if (value > 3) {
      throw std::invalid_argument("В четверичной СС допустимы только цифры от 0 до 3");
    }
    dataArray[index--] = value;
  }
}

Four::Four(const unsigned char *vals, const size_t n) {
  arraySize = n;
  dataArray = new unsigned char[arraySize];
  for (size_t i = 0; i < arraySize; ++i) {
    dataArray[i] = vals[i];
  }
}

Four::Four(const std::string &vals) {
  arraySize = vals.size();
  dataArray = new unsigned char[arraySize];

  for (size_t i = 0; i < arraySize; ++i) {
    if (vals[i] > '3' || vals[i] < '0') {
      throw std::invalid_argument("В четверичной СС допустимы только цифры от 0 до 3");
    }
    dataArray[i] = static_cast<unsigned char>(vals[arraySize - i - 1] - '0');
  }
}

Four::Four(const Four &other) {
  arraySize = other.arraySize;
  dataArray = new unsigned char[arraySize];
  
  for (size_t i = 0; i < arraySize; ++i) {
    dataArray[i] = other.dataArray[i];
  }
}

Four::Four(Four &&other) noexcept {
  arraySize = other.arraySize;
  dataArray = other.dataArray;
  other.arraySize = 0;
  other.dataArray = nullptr;
}

// === арифметические операции ===
Four Four::add(const Four &other) const {
  size_t newSize{};
  size_t maxLen = (arraySize > other.arraySize ? arraySize : other.arraySize);
  unsigned char sum{}, n{};
  unsigned char *buf = new unsigned char[maxLen + 1];

  for (size_t i = 0; i < maxLen; ++i) {
    sum = n + (i >= arraySize ? 0 : dataArray[i]) + (i >= other.arraySize ? 0 : other.dataArray[i]);
    buf[i] = sum % 4;
    n = sum / 4;
    ++newSize;
  }
  if (n) {
    buf[newSize++] = n;
  }
  Four res(buf, newSize);
  delete[] buf;
  return res;
}

Four Four::sub(const Four &other) const {
  if (le(other)) {
    return Four();
  }
  unsigned char n{};
  unsigned char *buf = new unsigned char[arraySize];
  size_t newSize = arraySize;

  for (size_t i = 0; i < arraySize; ++i) {
    unsigned char otherDigit = (i >= other.arraySize) ? 0 : other.dataArray[i];
    if (dataArray[i] - n >= otherDigit) {
      buf[i] = dataArray[i] - n - otherDigit;
      n = 0;
    } else {
      buf[i] = dataArray[i] - n + 4 - otherDigit;
      n = 1;
    }
  }
  while (newSize > 0 && buf[newSize - 1] == 0) {
    --newSize;
  }
  if (newSize == 0) {
    delete[] buf;
    return Four();
  }
  Four res(buf, newSize);
  delete[] buf;
  return res;
}

// === операции сравнения ===
bool Four::eq(const Four &other) const {
  if (arraySize != other.arraySize) {
    return false;
  }
  for (size_t i = 0; i < arraySize; ++i) {
    if (dataArray[i] != other.dataArray[i]) {
      return false;
    }
  }
  return true;
}

bool Four::gt(const Four &other) const {
  if (arraySize > other.arraySize) {
    return true;
  } else if (arraySize < other.arraySize) {
    return false;
  }
  for (size_t i = 0; i < arraySize; ++i) {
    if (dataArray[arraySize - 1 - i] < other.dataArray[arraySize - 1 - i]) {
      return false;
    } else if (dataArray[arraySize - 1 - i] > other.dataArray[arraySize - 1 - i]) {
      return true;
    }
  }
  return false;
}

bool Four::ge(const Four &other) const {
  if (arraySize > other.arraySize) {
    return true;
  } else if (arraySize < other.arraySize) {
    return false;
  }
  for (size_t i = 0; i < arraySize; ++i) {
    if (dataArray[arraySize - 1 - i] < other.dataArray[arraySize - 1 - i]) {
      return false;
    } else if (dataArray[arraySize - 1 - i] > other.dataArray[arraySize - 1 - i]) {
      return true;
    }
  }
  return true;
}

bool Four::lt(const Four &other) const {
  if (arraySize < other.arraySize) {
    return true;
  } else if (arraySize > other.arraySize) {
    return false;
  }
  for (size_t i = 0; i < arraySize; ++i) {
    if (dataArray[arraySize - 1 - i] > other.dataArray[arraySize - 1 - i]) {
      return false;
    } else if (dataArray[arraySize - 1 - i] < other.dataArray[arraySize - 1 - i]) {
      return true;
    }
  }
  return false;
}

bool Four::le(const Four &other) const {
  if (arraySize < other.arraySize) {
    return true;
  } else if (arraySize > other.arraySize) {
    return false;
  }
  for (size_t i = 0; i < arraySize; ++i) {
    if (dataArray[arraySize - 1 - i] > other.dataArray[arraySize - 1 - i]) {
      return false;
    } else if (dataArray[arraySize - 1 - i] < other.dataArray[arraySize - 1 - i]) {
      return true;
    }
  }
  return true;
}

std::ostream& Four::print(std::ostream& outputStream) const {
  if (arraySize > 0) {
    size_t i = arraySize;
    do {
      --i;
      outputStream << static_cast<char>(dataArray[i] + '0');
    } while (i > 0);
  }
  return outputStream;
}

Four::~Four() noexcept {
  if (dataArray != nullptr) {
    delete[] dataArray;
    dataArray = nullptr;
  }
  arraySize = 0;
}