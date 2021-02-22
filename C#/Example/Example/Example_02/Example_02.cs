//#define E02_VARIABLE
//#define E02_CONSTANT
#define E02_DATA_INPUT_OUTPUT

using System;

namespace Example.Example_02 {
	//! Example 2
	public class Example_02 {
#if E02_CONSTANT
		private const int CONSTANT_VALUE_A = 10;
		private const float CONSTANT_VALUE_B = 3.14f;

		private const string CONSTANT_STRING = "Hello, World!";
#endif			// #if E02_CONSTANT

		//! 초기화
		public static void Start(string[] args) {
#if E02_VARIABLE
			byte nByteA = byte.MaxValue;
			sbyte nByteB = sbyte.MaxValue;

			short nShortA = short.MaxValue;
			ushort nShortB = ushort.MaxValue;

			int nIntA = int.MaxValue;
			uint nIntB = uint.MaxValue;

			long nLongA = long.MaxValue;
			ulong nLongB = ulong.MaxValue;

			Console.WriteLine("===== 정수 출력 =====");
			Console.WriteLine("byte: {0}, {1}, {2}", sizeof(byte), nByteA, nByteB);
			Console.WriteLine("short: {0}, {1}, {2}", sizeof(short), nShortA, nShortB);
			Console.WriteLine("int: {0}, {1}, {2}", sizeof(int), nIntA, nIntB);
			Console.WriteLine("long: {0}, {1}, {2}", sizeof(long), nLongA, nLongB);

			float fFloat = float.MaxValue;
			double dblDouble = double.MaxValue;
			decimal mDecimal = decimal.MaxValue;

			Console.WriteLine("\n===== 실수 출력 =====");
			Console.WriteLine("float: {0}, {1}", sizeof(float), fFloat);
			Console.WriteLine("double: {0}, {1}", sizeof(double), dblDouble);
			Console.WriteLine("decimal: {0}, {1}", sizeof(decimal), mDecimal);

			char chChar = 'A';
			string oString = "Hello, World!";
			string 한글_변수 = "Hello, World!";

			Console.WriteLine("\n===== 문자(열) 출력 =====");
			Console.WriteLine("char: {0}, {1}", sizeof(char), chChar);
			Console.WriteLine("string: {0}, {1}", oString, 한글_변수);
#elif E02_CONSTANT
			Console.WriteLine("===== 컴파일 타임 상수 출력 =====");
			Console.WriteLine("int: {0}", Example_02.CONSTANT_VALUE_A);
			Console.WriteLine("float: {0}", Example_02.CONSTANT_VALUE_B);

			Console.WriteLine("string: {0}", Example_02.CONSTANT_STRING);
#elif E02_DATA_INPUT_OUTPUT
			Console.Write("수식 입력 : ");
			var oTokens = Console.ReadLine().Split(" ");

			int nLhs = int.Parse(oTokens[0]);
			int nRhs = int.Parse(oTokens[2]);

			char chOperator = char.Parse(oTokens[1]);
			Console.Write("결과 : ");

			switch(chOperator) {
				case '+': Console.WriteLine("{0}", nLhs + nRhs); break;
				case '-': Console.WriteLine("{0}", nLhs - nRhs); break;
				case '*': Console.WriteLine("{0}", nLhs * nRhs); break;
				case '/': Console.WriteLine("{0}", nLhs / (float)nRhs); break;
			}
#endif			// #if E02_VARIABLE
		}
	}
}
