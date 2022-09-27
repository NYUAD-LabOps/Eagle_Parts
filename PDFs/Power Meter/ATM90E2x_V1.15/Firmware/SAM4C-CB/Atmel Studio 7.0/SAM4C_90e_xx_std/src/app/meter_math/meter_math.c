//===================================================================
#include "target.h"
//-------------------------------------------------------------------

//-------------------------------------------------------------------

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

//================================================
//Description     ::	bcd chang to bin
//Function        ::	BCD_8BIN
//Input           ::	bcddata
//Output          ::	bcddata->bin
//Call            ::	none
//Effect          ::
//===============================================
uint8_t BCD_8BIN(uint8_t bcddata)
{
	return((bcddata>>4)*10+(bcddata&0x0f));
}
//================================================
//Description     ::	bin change to bcd
//Function        ::	BIN_TO_BCD
//Input           ::	bindata<0x64
//Output          ::	bindata->bcd
//Call            ::	none
//Effect          ::
//===============================================
uint16_t BIN_TO_BCD(uint8_t bindata)  
{
	uint16_t i;	
	i=(bindata/100);
	i=i<<4;
	i+=(bindata%100)/10;
	i=i<<4;
	i+=(bindata%100)%10;	
	return(i);		
}
//================================================
//Description     ::	two bits bcd data add
//Function        ::	BCD_2_Add
//Input           ::	addend,ptr
//Output          ::	(addend+*(ptr))->*(ptr)
//				  ::	carry
//Call            ::	BCD_8BIN,BIN_TO_BCD
//Effect          ::
//===============================================
uint8_t BCD_2_Add(uint8_t addend,uint8_t *point) 
{
	uint8_t i;
	uint8_t j;
	uint8_t carry=0;
	i=BCD_8BIN(addend);
	j=BCD_8BIN(*point);
	j=i+j;		
	if(j>=100)
	{
		carry=1;
		j=j-100;
	}
	*point=(uint8_t)BIN_TO_BCD(j);		
	return(carry);	
}
//================================================
//Description     ::	eight bits bcd data add
//Function        ::	BCD_8_Add
//Input           ::	*pointaddend,*pointaugend
//Output          ::	result->*pointend,carry
//Call            ::	BCD_8BIN,BIN_TO_BCD
//Effect          ::
//===============================================
uint8_t BCD_8_Add(uint8_t *pointadd,uint8_t *pointend)
{
	uint8_t carry=0;
	uint8_t i;
	uint8_t j;
	for(i=0;i<4;i++)
	{
		carry=BCD_2_Add(*(pointadd+i),(pointend+i));
		if(carry==1)
		{
			for(j=i+1;j<4;j++)
			{
				carry=BCD_2_Add(1,(pointend+j));
				if(carry==0)
					break;
			}
		}
	}
	return(carry);
}
//=========================================================
//Description     ::		bcd verify 
//Function        ::		BCD_Verify
//Input           ::		bcddata
//Output          ::		if failure return 1 else 0
//Call            ::		none
//Effect          ::
//=========================================================
uint8_t	BCD_Verify(uint8_t BCDData)
{
	if((BCDData&0x0f)>0x09||(BCDData&0xf0)>0x90)
		return(1);
	else
		return(0);
}
//=========================================================
//Description     ::		n byte bcd verify 
//Function        ::		N_Byte_BCDVerify
//Input           ::		ptr->first bcd,len=N 
//Output          ::		if failure return 1 else 0
//Call            ::		none
//Effect          ::
//=========================================================
uint8_t	N_Byte_BCDVerify(uint8_t *ptr, uint8_t len)
{
	uint8_t i;
	for(i=0; i<len; i++)
	{
		if(BCD_Verify(*(ptr+i)))
			break;		
	}
	if(i == len) 
		return 0x00;
	else 
		return 0x01;
}



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond