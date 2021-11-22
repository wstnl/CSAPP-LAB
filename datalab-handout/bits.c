/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * LiMingnui wstnl233@gmail.com 
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~( ~(~x & y) & ~(x & ~y) );
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int x = 1;
  x = x << 31;
  return x;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int conX = x + 1;
	x = conX + x;
	return !(!(conX)) & !(~x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int sig = 0xAA;
  sig = sig + (sig << 8) + (sig << 16) + (sig << 24);
  x = x & sig;
  return !(x ^ sig);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  x = ~x;
  return x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int xm, x3, x21, is3;
	xm = x ^ 0x30;
	xm = !(xm >> 4);
	
	x3 = x & 0x8;
	x21 = x & 0x6;

	is3 = !x3 | !x21;


  return xm & is3;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int xFalse;
	xFalse = !x;
	xFalse = xFalse << 31;
	xFalse = xFalse >> 31;

	y = y & (~xFalse);
	z = z & xFalse;
	x = y | z;
	return x;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
//  x = ~x + 1; // x = -x
//  y = x + y; // y = y - x, if x > y, 2's complement most significant is 1
//  y = y >> 31; // clear other significant 
//  return !y;
//  ***** code above this line is buggy *****
	int uNumMaker = ~(1 << 31);
	int ux = x & uNumMaker, xSign = (x >> 30) & 2, uy = y & uNumMaker, ySign = (y >> 30) & 2;
	int x2 = 0, y2 = 0;

	x2 = (ySign); // in order to compare significant bit: if x and y have different sign, the positive number will have 1x
	y2 = (xSign);

	ux = ~ux + 1;
	uy = ux + uy;
	uy = uy >> 31;
	
	x2 = x2 + (uy & 1);
	y2 = y2 + !uy;
	
	x2 = ~x2 + 1;
	y2 = x2 + y2;
	y2 = y2 >> 31;

	return (!y2);

}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
  return ~x & 1; // if x is not zero , x & 1 returns 1
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
//	int caBits = x ^ (x >> 1);
//	int ans = 0;
//	ans = ans + !(caBits >> 30);
//	ans = ans + !(caBits >> 29);
//	ans = ans + !(caBits >> 28);
//	ans = ans + !(caBits >> 27);
//	ans = ans + !(caBits >> 26);
//	ans = ans + !(caBits >> 25);
//	ans = ans + !(caBits >> 24);
//	ans = ans + !(caBits >> 23);
//	ans = ans + !(caBits >> 22);
//	ans = ans + !(caBits >> 21);
//	ans = ans + !(caBits >> 20);
//	ans = ans + !(caBits >> 19);
//	ans = ans + !(caBits >> 18);
//	ans = ans + !(caBits >> 17);
//	ans = ans + !(caBits >> 16);
//	ans = ans + !(caBits >> 15);
//	ans = ans + !(caBits >> 14);
//	ans = ans + !(caBits >> 13);
//	ans = ans + !(caBits >> 12);
//	ans = ans + !(caBits >> 11);
//	ans = ans + !(caBits >> 10);
//	ans = ans + !(caBits >> 9);
//	ans = ans + !(caBits >> 8);
//	ans = ans + !(caBits >> 7);
//	ans = ans + !(caBits >> 6);
//	ans = ans + !(caBits >> 5);
//	ans = ans + !(caBits >> 4);
//	ans = ans + !(caBits >> 3);
//	ans = ans + !(caBits >> 2);
//	ans = ans + !(caBits >> 1);
//	ans = ans + !caBits;
//
//
//	return 33 + (~ans);
//	草 !


	int cat = x ^ (x >> 1);
	int x16 = 0, x8 = 0, x4 = 0, x2 = 0, x1 = 0;
	int ans = 0;
	cat = cat | (cat >> 1);
	cat = cat | (cat >> 2);
	cat = cat | (cat >> 3);
	cat = cat | (cat >> 4);
	cat = cat | (cat >> 5);
	cat = cat | (cat >> 6);
	cat = cat | (cat >> 7);
	cat = cat | (cat >> 8);
	cat = cat | (cat >> 9);
	cat = cat | (cat >> 10);
	cat = cat | (cat >> 11);
	cat = cat | (cat >> 12);
	cat = cat | (cat >> 13);
	cat = cat | (cat >> 14);
	cat = cat | (cat >> 15);
	cat = cat | (cat >> 16);
	cat = cat | (cat >> 17);
	cat = cat | (cat >> 18);
	cat = cat | (cat >> 19);
	cat = cat | (cat >> 20);
	cat = cat | (cat >> 21);
	cat = cat | (cat >> 22);
	cat = cat | (cat >> 23);
	cat = cat | (cat >> 24);
	cat = cat | (cat >> 25);
	cat = cat | (cat >> 26);
	cat = cat | (cat >> 27);
	cat = cat | (cat >> 28);
	cat = cat | (cat >> 29);
	cat = cat | (cat >> 30);
//	cat = cat | (cat >> 31);

	x16 = (cat >> 16) & 1;
	ans = ans + (x16 << 4);

	x8 = (cat >> (8 + ans)) & 1;
	ans = ans + (x8 << 3);
	x4 = (cat >> (4 + ans)) & 1;
	ans = ans + (x4 << 2);
	x2 = (cat >> (2 + ans)) & 1;
	ans = ans + (x2 << 1);
	x1 = (cat >> (1 + ans)) & 1;
	ans = ans + (x1);
	ans = ans + (cat >> ans);
	return ans + 1;

}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	unsigned frac, exp, s, sign;
	frac = uf & 0x007fffff;
	exp  = uf & 0x7f800000;
	exp = exp >> 23;
	s    = (uf >> 22) & 1;
	sign = uf & 0x80000000;
	if(exp == 0xff){
		return uf;
	}
	else if(exp == 0x00) {
		if(s) exp = exp + 1;
		frac = frac << 1;
		frac = frac & 0x007fffff;
	}
	else{
		exp = exp + 1;
	}

	return (sign + (exp << 23) + frac);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	// bias = -126
	// exp range:[-126, 127]
	// INT_MAX == 2^31
	// exp = -24 : == 102
	// exp = 31 : == 157
	unsigned frac, exp, sign;
	frac = uf & 0x007fffff;
	frac = frac | 0x00800000;
	exp  = uf & 0x7f800000;
	exp = exp >> 23;
	sign = uf & 0x80000000;
	if(exp < 126)
		return 0;
	else if(exp <= 157){
		if(exp - 126 > 24){
			frac = frac << (exp - 150);
		}
		else{
			frac = frac >> (150 - exp);
		}
		if(sign)
			return ~frac + 1;
		else 
			return frac;
	}
	else 
		return 0x80000000u;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	unsigned ans = 0;
	unsigned frac = 1;
	unsigned exp;
	unsigned swiftLength;
	//unsigned sign = (x >> 31) & 1;
	if(x < -149)
		return 0;
	if(x < -126){ // x belongs to [-149, -127]
		swiftLength = x + 149;
		frac = frac << swiftLength; // swift [0, 22] steps
		ans = frac;
	
		return ans;
	}
	if(x <= 127){ // x belongs to [-126, 127]
		exp = x + 127;
		ans = exp << 23;
		return ans;
	}
	return 0x7f800000;
}
