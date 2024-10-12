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
            string[] inp = Console.ReadLine().Split();
            long xi = long.Parse(inp[0]), yi = long.Parse(inp[1]), hi = long.Parse(inp[2]);
            inp = Console.ReadLine().Split();
            long xj = long.Parse(inp[0]), yj = long.Parse(inp[1]), hj = long.Parse(inp[2]), v = long.Parse(inp[3]);

            long B = (Math.Abs(xj - xi) + Math.Abs(yj - yi) + hj) / v;
            long M = hi;

            if (M < B)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}
