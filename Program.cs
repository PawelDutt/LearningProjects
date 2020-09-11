using System;
using System.IO;


namespace PalindromeSearchInTXTWithCSharp
{
    class Program
    {
        static FileStream fwr = new FileStream(/*SOURCE CODE HERE*/"", FileMode.OpenOrCreate);
        static StreamWriter swr = new StreamWriter(fwr);
        private static void IsPalindrome(string l)
        {
            
            
            float wordLength = l.Length - 1;
            int counter = 0;

            if ((wordLength) % 2 == 0)
            {
                for (int i = 0; i < wordLength/2; i++)
                {
                    if (l[i] == l[(int)wordLength - i])
                    {
                        counter++;
                    }
                    if (counter == wordLength/2)
                    { 
                        swr.WriteLine(l);
                    }
                }
            }
            else if((wordLength) % 2 == 1)
            {
                for (int i = 0; i < wordLength-1; i++)
                {
                    if (l[i] == l[(int)wordLength - i])
                    {
                        counter++;
                    }
                    if (counter == wordLength-1)
                    {
                        swr.WriteLine(l);
                    }
                }
            }
            

        }
        static void Main(string[] args)
        {
            FileStream f = new FileStream(/*SOURCE CODE HERE*/"", FileMode.OpenOrCreate);
            StreamReader s = new StreamReader(f);
            string line = "";
            int counter = 0;
            while ((line = s.ReadLine()) != null)
            {
                IsPalindrome(line);
                counter++;
            }
            s.Close();
            f.Close();
            swr.Close();
            fwr.Close();
        }
    }
}
