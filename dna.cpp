#include <bits/stdc++.h>

using namespace std;

bool start = false;



void replaceAll(std::string &str, const std::string &from, const std::string &to)
{
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

string dnaToRna(string dna)
{
  //  string rna = "";

//    rna = dna;
    for(int i = 0; i<3;i++)  {
    // cout << dna << endl;
        // cout << dna[i];
        if (dna[i] == 'A')  {
            dna[i] = 'U';
        } else if (dna[i] == 'T')  {
            dna[i] = 'A';
        } else if (dna[i] == 'C')  {
            dna[i] = 'G';
        } else if (dna[i] == 'G')  {
            dna[i] = 'C';
        }
        // switch (dna[i]){
        //     case "A":
        //         dna[i] = "U";
        //         break;
        //     case "T":
        //         dna[i] = "A";
        //         break;
        //     case "C":
        //         dna[i] = "G";
        //         break;
        //     case "G":
        //         dna[i] = "C";
        // }
    } 



//    replace( dna.begin(), dna.end(), 'A', 'U');
//    replace( dna.begin(), dna.end(), 'T', 'A'); 
//    replace( dna.begin(), dna.end(), 'C', 'G');
//    replace( dna.begin(), dna.end(), 'G', 'C');

//    replaceAll(dna, "A", "U");
 //   replaceAll(dna, "T", "A");
 //   replaceAll(dna, "C", "G");
//    replaceAll(dna, "G", "C");
//    replaceAll(rna, "a", "U");
//    replaceAll(rna, "t", "A");
//    replaceAll(rna, "c", "G");
//    replaceAll(rna, "g", "C");
    return dna;
}

string rnaToProtein(string rna)
{
    string protein = "";
    if (rna[0] == 'U')
    {
        if (rna[1] == 'U')
        {
            if (rna[2] == 'U' || rna[2] == 'C')
            {
                protein = "Phe";
            }

            if (rna[2] == 'A' || rna[2] == 'G')
            {
                protein = "Leu";
            }
        }
        if (rna[1] == 'C')
        {
            protein = "Ser";
        }
        if (rna[1] == 'A')
        {
            if (rna[2] == 'U' || rna[2] == 'C')
            {
                protein = "Tyr";
            }
            if (rna[2] == 'A' || rna[2] == 'G')
            {
                protein = "Stop";
                return protein;
            }
        }
        if (rna[1] == 'G')
        {
            if (rna[2] == 'U' || rna[2] == 'C')
            {
                protein = "Cys";
            }
            if (rna[2] == 'A')
            {
                protein = "Stop";
            }
            if (rna[2] == 'G')
            {
                protein = "Trp";
            }
        }
    }
    if (rna[0] == 'C')
    {
        if (rna[1] == 'U')
        {
            protein = "Leu";
        }
        if (rna[1] == 'C')
        {
            protein = "Pro";
        }
        if (rna[1] == 'A')
        {
            if (rna[2] == 'U' || rna[2] == 'C')
            {
                protein = "His";
            }
            if (rna[2] == 'A' || rna[2] == 'G')
            {
                protein = "Gln";
            }
        }
        if (rna[1] == 'G')
        {
            protein = "Arg";
        }
    }
    if (rna[0] == 'A')
    {
        if (rna[1] == 'U')
        {
            if (rna[2] == 'U' || rna[2] == 'C' || rna[2] == 'A')
            {
                protein = "Ile";
            }
            if (rna[2] == 'G')
            {
                protein = "Start";
                start = true;
            }
        }
        if (rna[1] == 'C')
        {
            protein = "Thr";
        }
        if (rna[1] == 'A')
        {
            if (rna[2] == 'U' || rna[2] == 'C')
            {
                protein = "Asn";
            }
            if (rna[2] == 'A' || rna[2] == 'G')
            {
                protein = "Lys";
            }
        }
        if (rna[1] == 'G')
        {
            if (rna[2] == 'U' || rna[2] == 'C')
            {
                protein = "Ser";
            }
            if (rna[2] == 'A' || rna[2] == 'G')
            {
                protein = "Arg";
            }
        }
    }
if (rna[0] == 'G')  {
    if (rna[1] == 'U')  {
        protein = "Val";
    }
    if (rna[1] == 'C')  {
        protein = "Ala";
    }
    if (rna[1] == 'A')  {
        if (rna[2] == 'U' || rna[2] == 'C')  {
            protein = "Asp";
        }
        if (rna[1] == 'A' || rna[1] == 'G')  {
            protein = "Glu";
        }
    }
    if (rna[1] == 'G')  {
        protein = "Gly";
    }
}
    if (!start)
    {
        protein = "";
    }
    if (start && protein == "Stop")
    {
        return protein;
    }
    return protein;
}

int main()
{
    string n; //("CCTCTTTACACACGGAGGGTACGCTATTCTATGATTACACGGTTGCGATCCATAATC");
    cin >> n;
    for (int i = 0; i < n.length(); i++)
    {
        n[i] = toupper(n[i]);
        if (n[i] != 'A' && n[i] != 'T' && n[i] != 'C' && n[i] != 'G')
        {
            cout << "Invalid codon" << endl;
            return 0;
        }
    }
//    cout << n.length();
    if (n.length() % 3 != 0)
    {
        cout << n.length() % 3;
	cout << "Invalid codon length" << endl;
        return 0;
    }
    vector<string> arr(n.length() / 3);
    for (int i = 0; i < n.length() / 3; i++)
    {
        arr[i] = n.substr(i * 3, 3);
	cout << arr[i];
    }
    cout << endl;

    for (int i = 0; i < n.length() / 3; i++)
    {
        arr[i] = dnaToRna(arr[i]);
    }

    for (int i = 0; i < n.length() / 3; i++)
    {
        cout << arr[i];
        if (i == (n.length() / 3) - 1) {
            break;
        }
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < n.length() / 3; i++)
    {
        arr[i] = rnaToProtein(arr[i]);
    }


    for (int i = 0; i < n.length() / 3; i++)
    {
        cout << arr[i];
        if (arr[i] == "Stop")
        {
            break;
        }
        if (start) {
            cout << "-";
        };
    }
    cout << endl;
    // cout << n;
    return 0;
}
