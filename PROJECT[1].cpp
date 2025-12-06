#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    double berat, totalMinum;
    int usia;
    int aktivitas; // 1 = Ringan, 2 = Sedang, 3 = Berat

    // ================== INPUT =====================
    cout << "=== KALKULATOR KEBUTUHAN AIR ===\n";
    cout << "Masukkan berat badan (kg): ";
    cin >> berat;

    cout << "Masukkan usia (tahun): ";
    cin >> usia;

    // ================== TAMPILKAN PANDUAN AKTIVITAS =====================
    cout << "\n=== Panduan Tingkat Aktivitas ===\n";
    cout << "1. Ringan: Aktivitas minim, sebagian besar duduk atau santai\n";
    cout << "   Contoh: bekerja di kantor, membaca, menonton, jalan santai < 30 menit\n";
    cout << "2. Sedang: Aktivitas lebih banyak bergerak, olahraga ringan\n";
    cout << "   Contoh: jalan cepat 30–60 menit, berkebun ringan, jogging ringan\n";
    cout << "3. Berat: Aktivitas fisik intens atau olahraga berat\n";
    cout << "   Contoh: lari, renang, olahraga > 1 jam, kerja fisik berat\n";

    cout << "\nPilih tingkat aktivitas (1-3): ";
    cin >> aktivitas;

    // ================== HITUNG KEBUTUHAN AIR =====================
    double kebutuhan = berat * 35; // dasar
    if (aktivitas == 2) kebutuhan *= 1.2; // sedang
    else if (aktivitas == 3) kebutuhan *= 1.5; // berat

    double liter = kebutuhan / 1000.0;

    // Target otomatis
    double goal = kebutuhan;

    cout << "\n=== TRACKER KONSUMSI AIR ===\n";
    cout << "Berapa ml air yang sudah kamu minum hari ini? ";
    cin >> totalMinum;

    double persen = (totalMinum / goal) * 100;
    if (persen > 100) persen = 100;

    // ================== TIPS =========================
    string tips[5] = {
        "Minumlah segelas air setelah bangun tidur.",
        "Selalu bawa botol minum untuk menghindari dehidrasi.",
        "Gunakan alarm setiap 2 jam untuk minum air.",
        "Tambahkan irisan lemon agar air terasa lebih segar.",
        "Minum lebih banyak ketika cuaca panas atau berolahraga."
    };
    string tipsHarian = tips[rand() % 5];

    // ================== FAQ =========================
    string faqQ[4] = {
        "Berapa banyak air yang harus diminum per hari?",
        "Apakah minuman selain air putih dihitung?",
        "Apa tanda-tanda dehidrasi?",
        "Apakah minum terlalu banyak air berbahaya?"
    };
    string faqA[4] = {
        "Rata-rata 30–40 ml per kg berat badan.",
        "Ya, tetapi air putih tetap yang paling direkomendasikan.",
        "Mulut kering, pusing, urin gelap, dan tubuh lemas.",
        "Ya, dapat menyebabkan overhidrasi atau hiponatremia."
    };

    // ================== GENERATE HTML =========================
    ofstream file("report.html");

    file << "<!DOCTYPE html><html><head><title>Laporan Hidrasi</title>";
    file << "<style>";
    file << "body { font-family: Arial; background:#eef2f5; padding:20px; }";
    file << ".card { background:white; padding:20px; border-radius:10px; "
            "margin-bottom:20px; box-shadow:0 0 10px rgba(0,0,0,0.1); max-width:600px;}";
    file << "h2 { color:#0066cc; margin-top:0; }";
    file << ".bar { height:25px; background:#cce5ff; border-radius:10px; }";
    file << ".fill { height:25px; background:#007bff; width:" << persen << "%; "
            "border-radius:10px; }";
    file << "</style></head><body>";

    // Kebutuhan air + usia + aktivitas
    file << "<div class='card'>";
    file << "<h2>Kebutuhan Air Harian</h2>";
    file << "<p><b>Berat badan:</b> " << berat << " kg</p>";
    file << "<p><b>Usia:</b> " << usia << " tahun</p>";
    file << "<p><b>Tingkat aktivitas:</b> ";
    if (aktivitas == 1) file << "Ringan";
    else if (aktivitas == 2) file << "Sedang";
    else file << "Berat";
    file << "</p>";
    file << "<p><b>Kebutuhan air:</b> " << kebutuhan << " ml (" << liter << " liter)</p>";
    file << "</div>";

    // Tracker
    file << "<div class='card'>";
    file << "<h2>Tracker Konsumsi Air</h2>";
    file << "<p><b>Total minum hari ini:</b> " << totalMinum << " ml</p>";
    file << "<p><b>Target:</b> " << goal << " ml</p>";
    file << "<div class='bar'><div class='fill'></div></div>";
    file << "<p>Pencapaian: " << persen << "%</p>";
    file << "</div>";

    // Tips harian
    file << "<div class='card'>";
    file << "<h2>Tips Hidrasi Hari Ini</h2>";
    file << "<p>" << tipsHarian << "</p>";
    file << "</div>";

    // FAQ
    file << "<div class='card'>";
    file << "<h2>FAQ Seputar Konsumsi Air</h2>";
    for (int i = 0; i < 4; i++) {
        file << "<p><b>" << faqQ[i] << "</b><br>" << faqA[i] << "</p>";
    }
    file << "</div>";

    file << "</body></html>";
    file.close();

    cout << "\nFile 'report.html' BERHASIL dibuat! Silakan buka di browser.\n";

    return 0;
}
