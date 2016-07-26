using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ConsoleTest
{
    class Program
    {
        [DllImport("MainDLL.dll", EntryPoint = "countOfFiles", CallingConvention = CallingConvention.Cdecl, ExactSpelling = false, CharSet = CharSet.Ansi)]
        public static extern int countOfFiles();
        static void Main(string[] args)
        {
            int result = countOfFiles();
            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}
