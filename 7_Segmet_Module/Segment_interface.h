
#ifndef _SEGMENT_INTERFACE_H_
#define _SEGMENT_INTERFACE_H_



u8 Segment[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};

enum Segments{
	SegmentNo_0,
	SegmentNo_1,
	SegmentNo_2,
	SegmentNo_3,
	SegmentNo_4,
	SegmentNo_5,
	SegmentNo_6,
	SegmentNo_7,
	SegmentNo_8,
	SegmentNo_9,
           };
/*#define SegmentNo_0  (u8)0x3F
#define SegmentNo_1  (u8)0x06
#define SegmentNo_2  (u8)0x5B
#define SegmentNo3  (u8)0x4F
#define SegmentNo4  (u8)0x66
#define SegmentNo5  (u8)0x6D
#define SegmentNo6  (u8)0x7D
#define SegmentNo7  (u8)0x07
#define SegmentNo8  (u8)0xFF
#define SegmentNo9  (u8)0x6F
*/


#define  COUNT_UP   (u8)0
#define  COUNT_DOWN (u8)1

#define  COUNTER_START (u8)0
#define  COUNTET_END   (u8)1


//for Check Functions Status
#define RT_OK  (u8)0
#define RT_NOK (u8)1


//for Choose Cathode or Anode

#define CATHODE  0
#define ANODE    1


 typedef struct Segment_7_Config
{
	enum PORTS Copy_PortNo;
	enum Segments Copy_SEG_NO;
	u8 Copy_u8Start;
	u8 Copy_u8End;
	u8 Copy_u8UpOrDown;

}Segment_7_Config;



u8 SEG_7_U8CountingUpOrDown (Segment_7_Config *Copy_Config);
u8 SEG_7_U8SetSegmentNo(Segment_7_Config *Copy_Config);
u8 SEG_7_U8ClearSegmentNo(Segment_7_Config *Copy_Config);

#endif
