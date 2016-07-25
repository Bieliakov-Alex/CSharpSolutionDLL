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
        [DllImport("MainDLL.dll", EntryPoint = "listOfFiles", CallingConvention = CallingConvention.Cdecl, ExactSpelling = false, CharSet = CharSet.Ansi)]
        public static extern int listOfFiles();
        static void Main(string[] args)
        {
            int result = listOfFiles();
            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}
