/**
 *  Key is found by running apply key, then grepping for lines that have "the" and "and" in them.
 *  There are only eight occurances, and the solution is obvious.
 */

#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <vector>

void get_encrypted(std::vector<uint8_t> &encrypted) {
  std::ifstream file;
  file.open("inputs/p059_cipher.txt");
  while (file.good()) {
    std::string number_str;
    std::getline(file, number_str, ',');
    encrypted.push_back(stoi(number_str));
  }
}

void apply_key(
    const std::vector<uint8_t> &encrypted,
    const std::vector<uint8_t> &key,
    std::vector<uint8_t> &decrypted) {

  decrypted.resize(encrypted.size());

  for (int i = 0; i < encrypted.size(); i++) {
    decrypted[i] = encrypted[i] ^ key[i % key.size()];
  }
}

void try_all_keys(const std::vector<uint8_t> &encrypted) {
  uint8_t key_start = uint8_t('a');

  for (uint8_t i = 0; i < 26; i++) {
    for (uint8_t j = 0; j < 26; j++) {
      for (uint8_t k = 0; k < 26; k++) {
        std::vector<uint8_t> key = {
          uint8_t(key_start + i),
          uint8_t(key_start + j),
          uint8_t(key_start + k)
        };
        
        std::vector<uint8_t> decrypted;
        apply_key(encrypted, key, decrypted);

        std::string decrypted_str(decrypted.begin(), decrypted.end());
        std::string key_str(key.begin(), key.end());

        printf("%s: %s\n", key_str.c_str(), decrypted_str.c_str());
      }
    }
  }
}

int main() {
  std::vector<uint8_t> encrypted;
  get_encrypted(encrypted);

  // try_all_keys();

  std::vector<uint8_t> decrypted;
  std::vector<uint8_t> key = {'g', 'o', 'd'};
  apply_key(encrypted, key, decrypted);

  int sum = 0;
  for (int i = 0; i < decrypted.size(); i++) {
    sum += decrypted[i];
  }
  printf("Sum: %d\n", sum);
}

