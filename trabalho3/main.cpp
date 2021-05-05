#include "dbLinkedList.cpp"
#include "cityData.cpp"
#include <string>
#include <vector>

using namespace std;

void printRoutesVector(vector<dbLinkedList<cityData> *> *routes)
{
  if (routes->size())
  {
    cout << "Rotas Disponíveis" << endl;
    unsigned long int size = routes->size();

    for (int i = 0; i < size; i++)
    {
      cout << routes->at(i)->getRouteName();

      if (i + 1 != size)
        cout << " | ";
      else
        cout << "\n\n";
    }
  }
  else
    cout << "Nenhuma Rota Disponível!\n\n";
}

void clearVector(vector<dbLinkedList<cityData> *> *routes)
{
  unsigned long int size = routes->size();

  for (int i = 0; i < size; i++)
    delete routes->at(i);
}

void addCityInterface(dbLinkedList<cityData> *routeList)
{
  string cityName, cityDescription;
  cityData data;
  int index;

  do
  {
    system("clear");
    routeList->print();

    cout << "Para encerrar o processo, digite um índice menor do que 1" << endl;
    cout << "Digite o índice em que deseja adicionar a cidade" << endl;
    cin >> index;
    if (index > 0)
    {
      getchar();
      cout << "Digite o nome da Cidade\n";
      getline(cin, cityName);

      cout << "Digite a descrição desta Cidade\n";
      getline(cin, cityDescription);

      data.setCity(cityName);
      data.setDescription(cityDescription);

      routeList->addAt(data, index);
      cout << "Adicionada com sucesso" << endl;
      getchar();
    }
  } while (index > 0);

  system("clear");
  return;
}

void addRoute(vector<dbLinkedList<cityData> *> *routes)
{
  string routeName, cityName, cityDescription;
  dbLinkedList<cityData> *routeList = new dbLinkedList<cityData>();
  cityData data;

  cout << "Insira o nome da Rota (Ex: Curitiba -> Cascavel)" << endl;
  cin.ignore();
  getline(cin, routeName);

  routeList->setRouteName(routeName);
  data.setCity("Curitiba");
  data.setDescription("Capital do Paraná");

  routeList->add(data);

  do
  {
    system("clear");
    cout << "Quando finalizar a Lista de Cidades, entre com o valor 0 para o nome da cidade (Curitiba foi adicionada automaticamente como cidade inicial)\n\n";
    cout << "Digite o nome da Cidade\n";
    getline(cin, cityName);

    if (cityName != "0")
    {
      cout << "Digite a descrição desta Cidade\n";
      getline(cin, cityDescription);

      data.setCity(cityName);
      data.setDescription(cityDescription);

      routeList->add(data);
    }
  } while (cityName != "0");

  routes->push_back(routeList);

  system("clear");
  cout << "Rota adicionada com sucesso\n";
  getchar();
  system("clear");

  return;
}

void deleteRoute(vector<dbLinkedList<cityData> *> *routes)
{
  if (routes->size())
  {
    unsigned long int index;
    printRoutesVector(routes);
    cout << "Informe o índice da rota que deseja excluir (a contagem inicia em 0)" << endl;
    cin >> index;

    //desaloca a memória
    delete routes->at(index);
    //Remove do vector
    routes->erase(routes->begin() + index);

    system("clear");
    getchar();
    cout << "Rota removida com sucesso" << endl;
    getchar();
    return;
  }
  else
  {
    system("clear");
    getchar();
    cout << "Não há rotas a serem excluidas" << endl;
    getchar();
    system("clear");
    return;
  }
}

void routesManagementInterface(vector<dbLinkedList<cityData> *> *routes)
{
  int option;

  do
  {
    printRoutesVector(routes);

    cout << "1) Adicionar Rota" << endl;
    cout << "2) Excluir Rota" << endl;
    cout << "3) Adicionar cidadde a uma rota" << endl;
    cout << "4) Remover cidade de uma rota" << endl;
    cout << "5) Voltar ao menu Anterior" << endl;
    cout << "0) Sair" << endl;

    cin >> option;

    system("clear");
    switch (option)
    {
    case 0:
      clearVector(routes);
      break;
    case 1:
      addRoute(routes);
      break;

    case 2:
      deleteRoute(routes);
      break;

    case 3:
      if (routes->size())
      {
        printRoutesVector(routes);
        int index;
        cout << "Digite o índice da rota que deseja alterar" << endl;
        cin >> index;
        addCityInterface(routes->at(index));
      }
      break;

    case 4:
      cout << "menu em construção" << endl;
      break;

    case 5:
      return;

    default:
      cout << "Opção Indisponível\n"
           << endl;
      break;
    }

  } while (option);

  exit(0);
}

void mainInterface(vector<dbLinkedList<cityData> *> *routes)
{
  int option;

  do
  {
    cout << "Escolha uma das Opções" << endl;
    cout << "1) Gerenciar Rotas" << endl;
    cout << "2) Viajar" << endl;
    cout << "0) Sair" << endl;

    cin >> option;

    system("clear");
    switch (option)
    {
    case 0:
      clearVector(routes);
      break;

    case 1:
      routesManagementInterface(routes);
      break;

    case 2:
      cout << "Menu em Construção" << endl;
      break;

    default:
      cout << "Opção indisponível" << endl;
      break;
    }

  } while (option);

  return;
}

int main()
{
  vector<dbLinkedList<cityData> *> routes;

  mainInterface(&routes);

  return 0;
}