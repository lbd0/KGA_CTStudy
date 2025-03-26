#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <random>

// 🔹 랜덤한 Salt 생성 함수
std::string generateSalt(size_t length = 16) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, sizeof(charset) - 2);

    std::string salt;
    for (size_t i = 0; i < length; ++i) {
        salt += charset[distrib(gen)];
    }
    return salt;
}

// 🔹 SHA-256 해시 함수 (Salt 적용)
std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// 🔹 Salt를 적용하여 비밀번호 해싱
std::string hashPasswordWithSalt(const std::string& password, const std::string& salt) {
    return sha256(salt + password);
}

int main() {
    std::string password = "my_secure_password";

    // Salt 생성
    std::string salt = generateSalt();
    std::cout << "Generated Salt: " << salt << std::endl;

    // 비밀번호 + Salt 해싱
    std::string hashedPassword = hashPasswordWithSalt(password, salt);
    std::cout << "Hashed Password: " << hashedPassword << std::endl;

    return 0;
}
