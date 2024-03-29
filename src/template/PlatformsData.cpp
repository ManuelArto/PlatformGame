#include "../model/Platform.hpp"

const int NUMBER_TEMPLATES = 10;

static void storeNewRoomPlatforms(Platform *platforms[], int index_offset, int number_template, int offset, const int MAX_PLATFORMS_FOR_ROOM) {

	int i = index_offset;
	switch (number_template) {
	case 0:
		platforms[i++] = new Platform(3+offset, 6, 7);
		platforms[i++] = new Platform(8+offset, 4, 7);
		platforms[i++] = new Platform(14+offset, 2, 8);
		platforms[i++] = new Platform(23+offset, 4, 9);
		platforms[i++] = new Platform(32+offset, 6, 8);
		break;
	case 1:
		platforms[i++] = new Platform(5+offset, 6, 3);
		platforms[i++] = new Platform(9+offset, 4, 5);
		platforms[i++] = new Platform(16+offset, 5, 5);
		platforms[i++] = new Platform(22+offset, 3, 6);
		platforms[i++] = new Platform(28+offset, 1, 6);
		platforms[i++] = new Platform(33+offset, 5, 6);
		break;
	case 2:
		platforms[i++] = new Platform(3+offset, 6, 2);
		platforms[i++] = new Platform(5+offset, 4, 3);
		platforms[i++] = new Platform(8+offset, 2, 3);
		platforms[i++] = new Platform(11+offset, 6, 3);
		platforms[i++] = new Platform(13+offset, 6, 2);
		platforms[i++] = new Platform(18+offset, 4, 3);
		platforms[i++] = new Platform(19+offset, 6, 3);
		platforms[i++] = new Platform(23+offset, 5, 7);
		platforms[i++] = new Platform(28+offset, 3, 5);
		platforms[i++] = new Platform(32+offset, 1, 5);
		platforms[i++] = new Platform(37+offset, 3, 5);
		platforms[i++] = new Platform(42+offset, 5, 5);
		break;
	case 3:
		platforms[i++] = new Platform(5+offset, 6, 6);
		platforms[i++] = new Platform(12+offset, 5, 6);
		platforms[i++] = new Platform(18+offset, 3, 6);
		platforms[i++] = new Platform(19+offset, 6, 6);
		platforms[i++] = new Platform(27+offset, 5, 6);
		platforms[i++] = new Platform(33+offset, 3, 6);
		platforms[i++] = new Platform(40+offset, 6, 6);
		break;
	case 4:
		platforms[i++] = new Platform(6+offset, 6, 6);
		platforms[i++] = new Platform(11+offset, 4, 17);
		platforms[i++] = new Platform(16+offset, 2, 5);
		platforms[i++] = new Platform(27+offset, 2, 5);
		platforms[i++] = new Platform(27+offset, 6, 5);
		platforms[i++] = new Platform(33+offset, 4, 5);
		platforms[i++] = new Platform(38+offset, 6, 6);
		break;
	case 5:
		platforms[i++] = new Platform(5+offset, 6, 4);
		platforms[i++] = new Platform(10+offset, 4, 4);
		platforms[i++] = new Platform(15+offset, 5, 5);
		platforms[i++] = new Platform(20+offset, 3, 4);
		platforms[i++] = new Platform(25+offset, 1, 8);
		platforms[i++] = new Platform(29+offset, 5, 6);
		platforms[i++] = new Platform(36+offset, 3, 6);
		platforms[i++] = new Platform(41+offset, 6, 5);
		break;
	case 6:
		platforms[i++] = new Platform(7+offset, 6, 4);
		platforms[i++] = new Platform(12+offset, 4, 4);
		platforms[i++] = new Platform(16+offset, 2, 4);
		platforms[i++] = new Platform(21+offset, 2, 6);
		platforms[i++] = new Platform(21+offset, 3, 6);
		platforms[i++] = new Platform(21+offset, 4, 6);
		platforms[i++] = new Platform(21+offset, 5, 6);
		platforms[i++] = new Platform(21+offset, 6, 6);
		platforms[i++] = new Platform(21+offset, 7, 6);
		platforms[i++] = new Platform(28+offset, 2, 4);
		platforms[i++] = new Platform(32+offset, 4, 4);
		platforms[i++] = new Platform(36+offset, 6, 4);
		break;
	case 7:
		platforms[i++] = new Platform(7+offset, 2, 5);
		platforms[i++] = new Platform(12+offset, 4, 5);
		platforms[i++] = new Platform(17+offset, 6, 16);
		platforms[i++] = new Platform(33+offset, 4, 5);
		platforms[i++] = new Platform(38+offset, 2, 5);
		break;
	case 8:
		platforms[i++] = new Platform(4+offset, 4, 5);
		platforms[i++] = new Platform(10+offset, 6, 5);
		platforms[i++] = new Platform(11+offset, 2, 5);
		platforms[i++] = new Platform(19+offset, 3, 5);
		platforms[i++] = new Platform(28+offset, 4, 5);
		platforms[i++] = new Platform(36+offset, 2, 5);
		platforms[i++] = new Platform(45+offset, 6, 4);
		break;
	case 9:
		platforms[i++] = new Platform(6+offset, 6, 4);
		platforms[i++] = new Platform(11+offset, 4, 11);
		platforms[i++] = new Platform(15+offset, 2, 4);
		platforms[i++] = new Platform(26+offset, 4, 11);
		platforms[i++] = new Platform(29+offset, 2, 4);
		platforms[i++] = new Platform(39+offset, 6, 4);
		break;
	}
	while (i < MAX_PLATFORMS_FOR_ROOM+index_offset) {
		platforms[i++] = NULL;
	}
}
/*

1. 
┌──────────────────────────────────────────────────┐		P1 : x = 3, y = 7, length = 7;
│                                                  │		P2 : x = 8, y = 5, lenght = 7;
│                                                  │        P3 : x = 14, y = 3, length = 8;
│              ========                            │        P4 : x = 23, y = 5, length = 9;
│                                                  │        P5 : x = 32, y = 7, length = 8;
│        =======        =========                  │       
│                                                  │
│   =======                      ========          │
│                                                  │
└──────────────────────────────────────────────────┘

2. 
┌──────────────────────────────────────────────────┐
│                                                  │        P1: x = 5, y = 7, length = 3; 
│                            ======                │        P2: x = 9, y = 5, length = 5;
│                                                  │        P3: x = 16, y = 6, length = 5;
│                      ======                      │        P4: x = 22, y = 4, length = 6;
│         =====                                    │        P5: x = 28, y = 2, length = 6;
│                =====            ======           │        P6: x = 33, y = 6, length = 6;
│     ===                                          │
│                                                  │
└──────────────────────────────────────────────────┘

3. 															P1: x = 3, y = 7, length = 2;
┌──────────────────────────────────────────────────┐		P2: x = 5, y = 5, length = 3;
│                                                  │        P3: x = 8, y = 3, length = 3;
│                                =====             │        P4: x = 11, y = 5, length = 3; 
│        ===                                       │        P5: x = 13, y = 7, length = 2;
│                            =====    =====        │        P6: x = 18, y = 5, length = 3;
│     ===   ===    ===                             │        P7: x = 19, y = 7, length = 3;
│                       =======            =====   │        P8: x = 23, y = 6, length = 7;
│   ==        ==    ===                            │        P9: x = 28, y = 4, length = 5;
│                                                  │        P10: x = 32, y = 2, length = 5;
└──────────────────────────────────────────────────┘        P11: x = 37, y = 4, length = 5;
                                                            P12: x = 42, y = 6, length = 5;
4. 
┌──────────────────────────────────────────────────┐
│                                                  │        P1: x = 5, y = 7, length = 6;
│                                                  │        P2: x = 12, y = 6, length = 6;
│                                                  │        P3: x = 18, y = 4, length = 6;
│                  ======         ======           │        P4: x = 19, y = 7, length = 6;
│                                                  │        P5: x = 27, y = 6, length = 6;
│            ======         ======                 │        P6: x = 33, y = 4, length = 6;
│     ======        ======               ======    │        P7: x = 40, y = 7, length = 6;
│                                                  │ 
└──────────────────────────────────────────────────┘

5. 
┌──────────────────────────────────────────────────┐
│                                                  │        P1: x = 6, y = 7, length = 6;
│                                                  │        P2: x = 11, y = 5, length = 17;
│                =====      =====                  │        P3: x = 16, y = 3, length = 5;
│                                                  │        P4: x = 27, y = 3, length = 5;
│           =================     =====            │        P5: x = 27, y = 7, length = 5;
│                                                  │        P6: x = 33, y = 5, length = 5;
│      ======               =====      ======      │        P7: x = 38, y = 7, length = 6;
│                                                  │
└──────────────────────────────────────────────────┘

6.
┌──────────────────────────────────────────────────┐
│                                                  │        P1: x = 5, y = 7, length = 4;
│                         ========                 │        P2: x = 10, y = 5, length = 4;
│                                                  │        P3: x = 15, y = 6, length = 5;
│                    ====            ======        │        P4: x = 20, y = 4, length = 4;
│          ====                                    │        P5: x = 25, y = 2, length = 8;
│               =====         ======               │        P6: x = 29, y = 6, length = 6;
│     ====                                =====    │        P7: x = 36, y = 4, length = 6;
│                                                  |        P8: x = 41, y = 7, length = 5;
└──────────────────────────────────────────────────┘

7.                                                          P1: x = 7, y = 7, length = 4;
┌──────────────────────────────────────────────────┐        P2: x = 12, y = 5, length = 4;
│                                                  │        P3: x = 16, y = 3, length = 4;   
│                                                  │        P4: x = 21, y = 3, length = 6;  
│                ==== ====== ====                  │        P5: x = 21, y = 4, length = 6;
│                     ======                       │        P6: x = 21, y = 5, length = 6;
│            ====     ======     ====              │        P7: x = 21, y = 6, length = 6;
│                     ======                       │        P8: x = 21, y = 7, length = 6;
│       ====          ======         ====          │        P9: x = 21, y = 8, length = 6;
│                     ======                       │        P10: x = 28, y = 3, length = 4;
└──────────────────────────────────────────────────┘        P11: x = 32, y = 5, length = 4;
                                                            P12: x = 36, y = 7, length = 4;
8.
┌──────────────────────────────────────────────────┐
│                                                  │
│                                                  │        P1: x = 7, y = 3, length = 5;
│       =====                          =====       │        P2: x = 12, y = 5, length = 5;
│                                                  |        P3: x = 17, y = 7, length = 16;
│            =====                =====            │        P4: x = 33, y = 5, length = 5;
│                                                  │        P5: x = 38, y = 3, length = 5;
│                 ================                 │
│                                                  |
└──────────────────────────────────────────────────┘

9.
┌──────────────────────────────────────────────────┐                                
│                                                  │
│                                                  │        P1: x = 4, y = 5, length = 5;
│           =====                    =====         │        P2: x = 10, y = 7, length = 5;
│                   =====                          │        P3: x = 11, y = 3, length = 5;
│    =====                   =====                 │        P4: x = 19, y = 4, length = 5;
│                                                  │        P5: x = 28, y = 5, length = 5;
│          =====                              ==== │        P6: x = 36, y = 3, length = 5;
│                                                  │        P7: x = 45, y = 7, length = 4;
└──────────────────────────────────────────────────┘

10.
┌──────────────────────────────────────────────────┐
│                                                  │
│                                                  │        P1: x = 6, y = 7, length = 4;
│               ====          ====                 │        P2: x = 11, y = 5, length = 11;
│                                                  │        P3: x = 15, y = 3, length = 4;
│           ===========    ===========             │        P4: x = 26, y = 5, length = 11;
│                                                  │        P5: x = 29, y = 3, length = 4;
│      ====                             ====       │        P6: x = 39, y = 7, length = 4;
│                                                  │
└──────────────────────────────────────────────────┘

*/