//#define EXAMPLE_TYPE_VARIABLE
#define EXAMPLE_TYPE_DATA_INPUT_OUTPUT

using System;

namespace Example.Example_02 {
	//! Example 2
	public class Example_02 {
		//! 초기화
		public static void Start(string[] args) {
#if EXAMPLE_TYPE_VARIABLE
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
			string 한글로_된_변수 = "Hello, World!";

			Console.WriteLine("\n===== 문자(열) 출력 =====");
			Console.WriteLine("char: {0}, {1}", sizeof(char), chChar);
			Console.WriteLine("string: {0}, {1}", oString, 한글로_된_변수);
#elif EXAMPLE_TYPE_DATA_INPUT_OUTPUT
			Console.Write("수식 입력 : ");
			var oInputTokens = Console.ReadLine().Split(" ");

			int nLhs = int.Parse(oInputTokens[0]);
			int nRhs = int.Parse(oInputTokens[2]);

			char chOperator = char.Parse(oInputTokens[1]);
			Console.Write("결과 : ");

			switch(chOperator) {
				case '+': Console.WriteLine("{0}", nLhs + nRhs); break;
				case '-': Console.WriteLine("{0}", nLhs - nRhs); break;
				case '*': Console.WriteLine("{0}", nLhs * nRhs); break;
				case '/': Console.WriteLine("{0}", nLhs / (float)nRhs); break;
			}
#endif			// #if EXAMPLE_TYPE_VARIABLE
		}
	}
}
