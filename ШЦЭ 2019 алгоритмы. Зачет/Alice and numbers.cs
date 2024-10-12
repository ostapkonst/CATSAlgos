using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Alice_and_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inp = Console.ReadLine().Split();
            long N = long.Parse(inp[0]);
            long K = long.Parse(inp[1]);
            long V = N / K;
            Console.WriteLine(N - V);
        }
    }
}
