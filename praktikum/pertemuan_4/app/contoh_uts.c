#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data pegawai
typedef struct {
    char NIP[20];
    char nama[50];
    char golongan[5];
    int gaji_pokok;
    int tunjangan_anak;
    int uang_makan;
    int transport;
    int jumlah_absensi;
    int total_gaji;
} Pegawai;

// Fungsi untuk menghitung total gaji
void hitungTotalGaji(Pegawai *p) {
    int tunjangan_istri = 200000;
    p->tunjangan_anak = (p->gaji_pokok * 5 / 100); // 5% gaji pokok per anak

    if (p->jumlah_absensi > 20) {
        p->uang_makan *= 2; // Lembur uang makan 2x lipat
    }

    p->total_gaji = p->gaji_pokok + tunjangan_istri + p->tunjangan_anak + (p->uang_makan * p->jumlah_absensi) + (p->transport * p->jumlah_absensi);
}

// Fungsi untuk menampilkan data pegawai
void tampilkanPegawai(Pegawai pegawai[], int n) {
    printf("\nDaftar Pegawai setelah diurutkan (Bubble Sort berdasarkan Gaji Pokok):\n");
    printf("----------------------------------------------------------------------------\n");
    printf("| NIP        | Nama Pegawai | Gol | Gaji Pokok | Tunj. Anak | Uang Makan | Transport | Total Gaji |\n");
    printf("----------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-10s | %-12s | %-3s | %-10d | %-10d | %-10d | %-9d | %-10d |\n",
               pegawai[i].NIP, pegawai[i].nama, pegawai[i].golongan,
               pegawai[i].gaji_pokok, pegawai[i].tunjangan_anak,
               pegawai[i].uang_makan, pegawai[i].transport, pegawai[i].total_gaji);
    }
}

// Fungsi Bubble Sort berdasarkan Gaji Pokok
void bubbleSort(Pegawai pegawai[], int n) {
    int i, j;
    Pegawai temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pegawai[j].gaji_pokok > pegawai[j + 1].gaji_pokok) {
                temp = pegawai[j];
                pegawai[j] = pegawai[j + 1];
                pegawai[j + 1] = temp;
            }
        }
    }
}

// Fungsi utama
int main() {
    Pegawai pegawai[] = {
        {"123", "Andi", "3A", 1750000, 0, 30000, 30000, 22, 0},
        {"124", "Budi", "3B", 2500000, 0, 40000, 35000, 18, 0},
        {"125", "Citra", "3C", 3000000, 0, 50000, 40000, 20, 0},
        {"126", "Dewi", "3D", 3500000, 0, 60000, 45000, 25, 0}
    };

    int n = sizeof(pegawai) / sizeof(pegawai[0]);

    // Hitung total gaji untuk setiap pegawai
    for (int i = 0; i < n; i++) {
        hitungTotalGaji(&pegawai[i]);
    }

    // Urutkan dengan Bubble Sort berdasarkan Gaji Pokok
    bubbleSort(pegawai, n);

    // Tampilkan data setelah sorting
    tampilkanPegawai(pegawai, n);

    return 0;
}
