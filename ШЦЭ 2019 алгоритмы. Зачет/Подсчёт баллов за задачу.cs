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
            string[] inp1;
            string inp2;

            using (StreamReader sr = new StreamReader("input.txt"))
            {
                N = int.Parse(sr.ReadLine());
                inp1 = sr.ReadLine().Split();
                inp2 = sr.ReadLine();
            }

            int sum = 0;
            for (int i = 0; i < N; i++)
            {
                if (inp2[i] == '+')
                {
                    sum += int.Parse(inp1[i]);
                }
            }

            using (StreamWriter sw = new StreamWriter("output.txt"))
            {
                sw.WriteLine(sum);
            }
        }
    }
}
