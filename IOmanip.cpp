#include "IOmanip.h"

void Assign(vector<stud> &obj){

    bool pass = true;
    bool program = true;
    int counter = 0;
    char c = ' ';
    int option = 0;

    while(program){
    
    cout << " Pasrinkite studento pridėjimo eigą: " << endl;
    cout << " (1) Duomenis suvesti ranka. " << endl; 
    cout << " (2) Atsitiktinai generuoti tik studentų pažymius" << endl;
    cout << " (3) Atsitiktinai generuoti visus studentų duomenis" << endl;
    cout << " (4) Uždaryti programą "<< endl;

    cin >> option;
    ClearCin();

    switch (option){
        case (1):{
            program = false;
            while(pass){
                cout << " Ar norite pridėti studentą? (Y/N) " << endl;
                cin >> c;
                ClearCin();
                switch (c){
                    case 'Y':
                    {
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).vard = StringParameters();
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).pav = StringParameters();
                        cout << "Įveskite " << counter+1 << "-o studento namų darbų pažymius ( Jei norite baigti, įveskite 11) "<<endl;
                        bool ndCheck = true;
                        int tempgrade = 0;
                        while(ndCheck){
                            tempgrade = GradingParameters();
                            if(tempgrade == 11){
                                ndCheck=false;
                                break;
                            }
                            else{
                                obj.at(counter).nd.push_back(tempgrade);
                            }
                        }
                        int s = obj.at(counter).nd.size();
                        for(const int& i : obj.at(counter).nd){
                            obj.at(counter).FinalAverage += i;
                        }
                        cout << "Įveskite " << counter+1 << "-o studento egzamino rezultatą :  ";
                        obj.at(counter).egz = ExamParameters();
                        if(s >= 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                            obj.at(counter).median = 0.6*obj.at(counter).egz;
                        }
                        counter++;
                        break;
                    }
                    case 'N':
                    {
                        cout << " Stabdomas studentų pridėjimas... "<<endl;
                        pass = false;
                        if(counter == 0){
                            cout << " Studentų informacijos nėra " << endl;
                            cout << " Programa stabdoma "<< endl;
                            exit(0);
                        }
                        break;
                    }
                    default:
                    {
                        cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
                        break;
                    }
                }
            }
            break;
        }
        case (2):
        {
            program = false;
            cout << " Įveskite namų darbų skaičių:  " << endl;
            int numberOfHw = 0;
            numberOfHw = StartParameters();
            while(pass){

                cout << " Ar norite pridėti studentą? (Y/N) " << endl;
                cin >> c;
                ClearCin();

                switch (c){
                    case 'Y':
                    {
                        obj.resize(counter+1);
                        cout << "Įveskite " << counter+1 << " studento vardą :  ";
                        obj.at(counter).vard = StringParameters();
                        cout << "Įveskite " << counter+1 << " studento pavardę :  ";
                        obj.at(counter).pav = StringParameters();
                        RandomGrades(obj, counter, numberOfHw);
                        int s = obj.at(counter).nd.size();
                        if(s >= 1){
                            getAverage(obj, s, counter);
                            getMedian(obj, s, counter);
                        }
                        else{
                            obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                            obj.at(counter).median = 0.6*obj.at(counter).egz;
                        }
                        counter++;
                        break;
                    }
                    case 'N':
                    {
                        cout << " Stabdomas studentų pridėjimas... "<<endl;
                        pass = false;
                        if(counter == 0){
                            cout << " Studentų informacijos nėra " << endl;
                            cout << " Programa stabdoma "<< endl;
                            exit(0);
                        }
                        break;
                    }
                    default:
                    {
                        cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
                        break;
                    }
                }
            }
            break;
        }
        case (3):
        {
            program = false;
            cout << " Įveskite studentų skaičių:  " << endl;
            int numberOfSt = 0;
            numberOfSt = StartParameters();
            cout << " Įveskite namų darbų skaičių:  " << endl;
            int numberOfHw = 0;
            numberOfHw = StartParameters();
            for(counter; counter < numberOfSt; counter++){
                obj.resize(counter+1);
                RandomNames(obj, counter);
                RandomGrades(obj, counter, numberOfHw);
                int s = obj.at(counter).nd.size();
                if(s >= 1){
                    getAverage(obj, s, counter);
                    getMedian(obj, s, counter);
                }
                else{
                    obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                    obj.at(counter).median = 0.6*obj.at(counter).egz;
                }
            }
            break;
        }
        case (4):
        {
            program = false;
            cout << " Programos darbas baigiamas " << endl;
            exit(0);
            break;
        }
        default:{
            cout << " Netinkamas įvesties formatas, bandykite dar kartą :   " << endl;
            break;
        }
    }
}
}

void Print (vector<stud> &obj, bool countByAvg){
    int s = obj.size();

    if(countByAvg){
        cout << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
        for (int z = 0; z<70; z++){ cout << '-'; }
        cout << endl;
        for(int i = 0; i<s; i++){
            cout << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).FinalAverage << endl;
        }
    }
    else{
        cout << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
        for (int z = 0; z<70; z++){ cout << '-'; }
        cout << endl;
        for(int i = 0; i<s; i++){
            cout << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).median << endl;
        }
    }
}

void readFile(vector<stud> &obj, const string filename){

    int s = 0;
    int counter = 0;
    auto start = std::chrono::high_resolution_clock::now();
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "Klaida!  Failo atidarymo klaida " << filename << endl;
        exit(0);
    }
    try{
        string line;
        getline(file, line);

        while (getline(file, line)){
            stud* temp = new stud;
            istringstream iss(line);
            if (!(iss >> temp->vard >> temp->pav)){
                cerr << "Klaida!  Studento vardo ir pavardės skaitymo nuo failo klaida " << filename << endl;
                continue;
            }

            int number;

            while (iss >> number){

                temp->nd.push_back(number);
                temp->FinalAverage += number;
            }

            if (temp->nd.empty()){

                cerr << "Klaida!  Studento pažymių skaitymo nuo failo klaida " << filename << endl;
                continue;
            }

            temp->egz = temp->nd.back();
            temp->nd.pop_back();
            temp->FinalAverage -= temp->egz;
            s = temp->nd.size();
            obj.push_back(*temp);
            delete temp;

            if(s >= 1){

                getAverage(obj, s, counter);
                getMedian(obj, s, counter);

            }
            else{

                obj.at(counter).FinalAverage = 0.6*obj.at(counter).egz;
                obj.at(counter).median = 0.6*obj.at(counter).egz;

            }
            counter++;
        }
    }
    catch(const exception& e){
        cerr << " Klaida!  Skaitymo nuo failo klaida " << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << " Read time:  " << endl;
    cout<<diff.count()<<endl; 
    ifstream fclose(filename);
}

void PrintFile(vector<stud> &obj, bool countByAvg){

    auto start = std::chrono::high_resolution_clock::now();
    ofstream PrintOut("output.txt");
    if (!PrintOut.is_open()){
        cerr << "Klaida!  Failo atidarymo klaida." << endl;
        return;
    }
    try{
        ostringstream buffer;
        int s = obj.size();

        if(countByAvg){
            buffer << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Vid.)" << endl;
            for (int z = 0; z<70; z++){ buffer << '-'; }
            buffer << endl;
            for(int i = 0; i<s; i++){
                buffer << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).FinalAverage << endl;
            }
        }
        else{
            buffer << left << setw(26) << "Vardas"  << setw(26) << "Pavardė" << setw(15) << left << "Galutinis (Med.)" << endl;
            for (int z = 0; z<70; z++){ buffer << '-'; }
            buffer << endl;
            for(int i = 0; i<s; i++){
                buffer << left << setw(26) << obj.at(i).vard << setw(26) << obj.at(i).pav << setw(15) << left << fixed << setprecision(2) << obj.at(i).median << endl;
            }
        }
        PrintOut << buffer.str();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << " Print time:  " << diff.count() << endl;;
        PrintOut.close();
    }
    catch (const exception& e){
        cerr << " Klaida!  Įrašymo į failą klaida " << endl;
    }
}