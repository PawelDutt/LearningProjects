using System;
using System.Diagnostics;

namespace ConsoleApp1
{
    class Program
    {
        public static bool end = false;
        static void Main(string[] args)
        {

            Process.Start("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", "https://www.youtube.com");


            Console.WriteLine("POSZLO");
        }
    }
}
