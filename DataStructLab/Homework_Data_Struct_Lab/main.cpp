
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Her blob icin gerekli bilgileri hesaplayan recursive fonksiyon
void findBlob(char** matrix, int rows, int cols, int r, int c,
              int& pixelCount, double& sumX, double& sumY)
{
    // Matrisin sinirlari disindaysa geri don
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    // Bu konumda blob pikseli yoksa geri don
    if (matrix[r][c] != 'X' && matrix[r][c] != 'x')
        return;

    // Bu pikseli ziyaret edildi olarak isaretle
    matrix[r][c] = '#';

    // Piksel sayisini artir
    pixelCount++;

    // Sutun koordinati x, satir koordinati y olarak kabul edilir
    sumX += c;
    sumY += r;

    // Dört komsuya recursive olarak git
    findBlob(matrix, rows, cols, r - 1, c,
             pixelCount, sumX, sumY); // Yukari

    findBlob(matrix, rows, cols, r + 1, c,
             pixelCount, sumX, sumY); // Asagi

    findBlob(matrix, rows, cols, r, c - 1,
             pixelCount, sumX, sumY); // Sol

    findBlob(matrix, rows, cols, r, c + 1,
             pixelCount, sumX, sumY); // Sag
}

int main()
{
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    // Dosyayi ac
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    int rows, cols;

    // Ilk satirdan satir ve sutun sayilarini oku
    file >> rows >> cols;

    // Boyutlarin gecerli olup olmadigini kontrol et
    if (rows <= 0 || cols <= 0)
    {
        cout << "Error: Invalid matrix dimensions!" << endl;
        return 1;
    }

    // Baslik satirindan sonraki satira gec
    file.ignore(10000, '\n');

    // Iki boyutlu dinamik karakter dizisi olustur
    char** matrix = new char*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];

        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = ' ';
        }
    }

    // Dosyadaki pikselleri oku
    string line;

    for (int i = 0; i < rows; i++)
    {
        if (!getline(file, line))
            line = "";

        for (int j = 0; j < cols && j < (int)line.length(); j++)
        {
            if (line[j] == 'X' || line[j] == 'x')
                matrix[i][j] = 'X';
            else
                matrix[i][j] = ' ';
        }
    }

    file.close();

    // Girdi matrisini ekrana yazdir
    cout << "\nInput Matrix:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j];
        }

        cout << endl;
    }

    // Tum blob'lari bul
    int blobNumber = 0;

    cout << "\nBlob Results:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 'X' || matrix[i][j] == 'x')
            {
                int pixelCount = 0;
                double sumX = 0;
                double sumY = 0;

                blobNumber++;

                // Bu blob'un tum bagli piksellerini recursive bul
                findBlob(matrix, rows, cols, i, j,
                         pixelCount, sumX, sumY);

                // Kutle merkezini hesapla
                double centerX = sumX / pixelCount;
                double centerY = sumY / pixelCount;

                cout << fixed << setprecision(2);

                cout << "Blob " << blobNumber << ":" << endl;
                cout << "Number of pixels: " << pixelCount << endl;
                cout << "Center of mass: ("
                     << centerX << ", " << centerY << ")" << endl;
                cout << endl;
            }
        }
    }

    // Dinamik belleði serbest birak
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}

