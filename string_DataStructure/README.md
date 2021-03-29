Dynamic String Array:
-Perubahan:
 -Struct Dynamic Array menyimpan data berupa char** (variabel arr)
 -Return type untuk fungsi back, front, dan getAt berubah dari int menjadi char*
 -Parameter value fungsi pushBack dan setAt menjadi tipe char[MAX_LEN+1]
 -Malloc dilakukan dua kali:
  -Pertama, untuk pointer to char pointer/pointer to string (fungsi init, line: 41; fungsi pushBack, line: 57) sebesar capacity dynamic array pada arr atau arr dari string
  -Kedua, untuk pointer to char (fungsi init, line: 43; fungsi pushBack, line: 59) sebesar panjang karakter maksimal dari string yang ingin disimpan pada setiap index dari arr string
 -Pada setiap assignment elemen array, diganti menggunakan strcpy (line: 63, 69, 94, 96
 -Untuk printf, dari %d menjadi %s

Linked String List:
Perubahan:
-Node menyimpan data dalam bentuk char dengan kapasitas panjang string maksimal+1
-Parameter value fungsi pushFront, pushBack, insertAt, remove berubah tipe dari int ke char*
-Return type fungsi front, back, getAt diganti menjadi type char*
-Assigment dari value ke data menggunakan strcpy (line: 64, 87, 143)
-Untuk printf, dari %d menjadi %s
