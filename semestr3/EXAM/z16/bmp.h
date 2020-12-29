#pragma pack(1)
typedef struct BMPHEAD_

  {                                                              
    unsigned short int Signature ;              // Must be 0x4d42 == ”BM”               //0
    unsigned long FileLength ;                  // в байтах                                                          //2
    unsigned long Zero ;                           // Must be 0                                                          //6
    unsigned long Ptr ;                              // смещение к области данных          //10
    unsigned long Version ;// длина оставшейся части заголовка=0x28          //14
    unsigned long Width ;          // ширина изображения в пикселах                 //18
    unsigned long Height ;         // высота изображения в пикселах                  //22
    unsigned short int   Planes ;                // к-во битовых плоскостей                             //26
    unsigned short int   BitsPerPixel ;       // к-во бит на на пиксел       //28
    unsigned long Compression ;              // сжатие: 0 или 1 или 2                    //30
    unsigned long SizeImage ;                   // размер блока данных в байтах      //34
    unsigned long XPelsPerMeter ;           // в ширину: пикселов на метр          //38
    unsigned long YPelsPerMeter ;           // в высчоту: пикселов на метр        //42
    unsigned long ClrUsed ;      // к-во цветов в палитре                   //46
    unsigned long ClrImportant ; // к-во используемых цветов в палитре //50    
    unsigned char pal[256][4];
    unsigned char (**v)[4]; //true color
    
    int **g; //greyscale, 0<=g[i][j]<256 || bitmap
  }BMPHEAD ;
  
#pragma pack()
