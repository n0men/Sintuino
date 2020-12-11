#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123

// C Major

int C1Maj[] = { C1, D1, E1, F1, G1, A1, B1 };
int C1PenM[] = { C1, D1, E1, G1, A1 };
int C1min[] = { C1, D1, DS1, F2, G2, GS2, AS2 };
int C1minA[] = { C1, D1, DS1, F2, G2, GS2, A2 };
int C1Penm[] = { C1, DS1, F2, G2, AS2 };
//scale blues

// C# Major

int CS1Maj[] = { CS1, DS1, F1, FS1, GS1, AS1, C2 };

//D Major 

int D1Maj[] = { D1, E1, FS1, G1, A1, B1, CS2 };

// D# Major 

int DS1Maj[] = { DS1, F1, G1, GS1, AS1, C2, D2, DS2 };

// E Major

int E1Major[] = { E1, FS1, GS1, A1, B1, CS2, DS2, E };

// F Major 

int F1Major[] = { F1, G1, A1, AS1, C2, D2, E2 };

// F# Major

int FS1Major[] = { FS1, GS1, AS1, B1, CS2, DS2, F2 };

//G Major

int GMajor[] = { G1, A1, B1, C2, D2, E2, FS2 };

//G # Major 

int GSMajor[] = { GS1, AS1, C2, CS2, DS2, F2, G2 };

//A Major 

int AMajor[] = { A1, B1, CS2, D2, E2, FS2, GS2 };

//A# Major

int ASMajor = { AS1, C2, D2, DS2, F2, G2, A2 };

//B Major

int BMajor = { B1, CS2, DS2, E2, FS2, GS2, AS2 };
