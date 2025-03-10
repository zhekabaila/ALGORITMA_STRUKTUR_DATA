#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

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

Pegawai pegawai[MAX] = {
    {"121", "XK", "3D", 4000000, 1212, 123, 123, 12, 1},
};
int jumlahPegawai = 1;

typedef struct {
    char golongan[5];
    int gajiPokok;
    int uangMakan;
    int transport;
} Golongan;

Golongan golongan[4] = {
    {"3A", 1750000, 30000, 30000},
    {"3B", 2500000, 40000, 35000},
    {"3C", 3000000, 50000, 40000},
    {"3D", 3500000, 60000, 45000},
};

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

void showData() {
    printf("\n=============================================================================================================================================\n");
    printf("============================================================ Data Pegawai ===================================================================\n");
    printf("=============================================================================================================================================\n");
    printf("| %-10s | %-20s | %-10s | %-12s | %-15s | %-12s | %-10s | %-15s | %-12s |\n",
           "NIP", "Nama", "Golongan", "Gaji Pokok", "Tunjangan Anak", "Uang Makan", "Transport", "Jumlah Absensi", "Total Gaji");
    printf("=============================================================================================================================================\n");

    for (int i = 0; i < jumlahPegawai; i++) {
        printf("| %-10s | %-20s | %-10s | %-12d | %-15d | %-12d | %-10d | %-15d | %-12d |\n",
               pegawai[i].NIP, pegawai[i].nama, pegawai[i].golongan,
               pegawai[i].gaji_pokok, pegawai[i].tunjangan_anak,
               pegawai[i].uang_makan, pegawai[i].transport,
               pegawai[i].jumlah_absensi, pegawai[i].total_gaji);
    }

    printf("=============================================================================================================================================\n");
}

void createData() {
    Pegawai pegawaiBaru;
    int jumlahAnak;

    printf("Buat Data Pegawai Baru:\n");
    
    if (jumlahPegawai > MAX) {
        printf("Sudah mencapai batas penyimpanan!\n");
    }

    printf("NIP             > ");
    scanf("%s", pegawaiBaru.NIP);
    getchar();

    printf("Nama           > ");
    fgets(pegawaiBaru.nama, sizeof(pegawaiBaru.nama), stdin);
    pegawaiBaru.nama[strlen(pegawaiBaru.nama) - 1] = '\0';

    printf("Golongan            > ");
    scanf("%s", pegawaiBaru.golongan);
    getchar();

    printf("Jumlah Anak        > ");
    scanf("%d", &jumlahAnak);
    getchar();

    printf("Jumlah Absensi     > ");
    scanf("%d", &pegawaiBaru.jumlah_absensi);
    getchar();

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(golongan[i].golongan, pegawaiBaru.golongan) == 0) {
            pegawaiBaru.gaji_pokok = golongan[i].gajiPokok;
            pegawaiBaru.uang_makan = golongan[i].uangMakan;
            pegawaiBaru.transport = golongan[i].transport;
            break;
        }
    }

    pegawaiBaru.tunjangan_anak = (pegawaiBaru.gaji_pokok * 0.05) / jumlahAnak;
    pegawaiBaru.uang_makan = pegawaiBaru.jumlah_absensi > 20 ? pegawaiBaru.uang_makan * 2 : pegawaiBaru.uang_makan;
    pegawaiBaru.total_gaji = pegawaiBaru.gaji_pokok + pegawaiBaru.uang_makan + pegawaiBaru.transport + pegawaiBaru.tunjangan_anak;

    pegawai[jumlahPegawai] = pegawaiBaru;
    jumlahPegawai++;
}

int main() {
    int pilihan;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tampilkan Data Pegawai\n");
        printf("2. Tambah Data Pegawai\n");
        printf("3. Hapus Data Pegawai (Belakang)\n");
        printf("0. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                bubbleSort(pegawai, jumlahPegawai);
                showData();
                break;
            case 2:
                createData();
                break;
            case 3:
                // deleteData();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}
