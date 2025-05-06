#include <DHT.h>

#define DHTPIN 2          // Pin untuk sensor DHT11
#define DHTTYPE DHT11     // Jenis sensor yang digunakan (DHT11)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Mulai komunikasi serial dengan baud rate 9600
  dht.begin();         // Inisialisasi sensor DHT11
}

void loop() {
  // Membaca suhu dan kelembapan dari sensor
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  // Mengecek apakah pembacaan berhasil
  if (isnan(suhu) || isnan(kelembapan)) {
    Serial.println("Gagal membaca sensor!");
    return;
  }

  // Mengirimkan data dalam format yang lebih terstruktur
  Serial.print("T:");
  Serial.print(suhu, 2);  // Menampilkan suhu dengan 2 digit setelah koma
  Serial.print(";H:");
  Serial.println(kelembapan, 2);  // Menampilkan kelembapan dengan 2 digit setelah koma

  delay(100);  // Menunggu 2 detik sebelum pembacaan berikutnya
}
