SECTIONS
{
	. = 0x8000000;
	.rom (COPY):
	{
		KEEP(*.o(.rom))
	}
 	. = 0x80000C0;
	.OPStartVectorCaller :
	{
		*.o(.OPStartVectorCaller)
		. = ALIGN(1);
	} 
	
	. = 0x80BCFA8;
	.SkipNintendoOP :
	{
		*.o(.SkipNintendoOP)
		. = ALIGN(1);
	}
	
	. = 0x23*4+0x8C1071C;
	.ApocalypseEntry :
	{
		*.o(.ApocalypseEntry)
		. = ALIGN(1);
	}
	. = 4+0x8D61A18;
	.FireAnimationID :
	{
		*.o(.FireAnimationID)
		. = ALIGN(1);
	}
	. = 0x9000000;
	.text :
	{
		*(.text);
	}	
	.rodata :
	{
		*(.rodata)
		. = ALIGN(4);
	} 
}