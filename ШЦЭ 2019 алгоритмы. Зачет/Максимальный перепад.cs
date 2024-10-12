using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace Alice_and_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            int N;
            long[,] array;

            using (StreamReader sr = new StreamReader("input.txt"))
            {
                N = int.Parse(sr.ReadLine());
                array = new long[N + 2, N + 2];
                for (int i = 1; i <= N; i++)
                {
                    string[] inp = sr.ReadLine().Split();
                    for (int j = 1; j <= N; j++)
                    {
                        array[i, j] = long.Parse(inp[j - 1]);
                    }
                }
            }

            for (int i = 1; i <= N; i++)
            {
                array[0, i] = array[1, i];
                array[N + 1, i] = array[N, i];
                array[i, 0] = array[i, 1];
                array[i, N + 1] = array[i, N];
            }

            long max = 0;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    long v = array[i, j];
                    max = Math.Max(Math.Max(
                    Math.Max(Math.Abs(array[i, j - 1] - v), Math.Abs(array[i, j + 1] - v)),
                    Math.Max(Math.Abs(array[i + 1, j] - v), Math.Abs(array[i - 1, j] - v))
                    ), max);
                }
            }

            using (StreamWriter sw = new StreamWriter("output.txt"))
            {
                sw.WriteLine(max);
            }
        }
    }
}
