#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// ��ü ����ϴ� �Լ�
template <typename pair1, typename pair2>
void print_umap1(unordered_map<pair1, pair2> umap) 
{
	for (auto& iter : umap) 
	{
		cout << iter.first << " : " << iter.second << " ";
	}
	cout << endl;
}

/// �ʿ��� Ű�� ���� ����ϴ� �Լ� 1
template <typename pair1, typename pair2>
void print_key_as_value_map1(unordered_map<pair1, pair2> umap, pair1 key) 
{
	if (umap.find(key) != umap.end()) 
	{
		cout << umap.find(key)->second;
	}
	cout << endl;
}

/// �ʿ��� Ű�� ���� ����ϴ� �Լ� 2
template <typename pair1, typename pair2>
void print_key_as_value_map2(unordered_map<pair1, pair2> umap, pair1 key) 
{
	try
	{
		cout << umap.at(key) << endl;
	}
	catch (const std::exception&)
	{
		cout << "����" << endl;
	}
}

int main() {
	unordered_map<int, int> um;

	// �ʿ� �����ϴ� ���
	um.insert({ 1, 3 });				// ��� 1
	um.insert(pair<int, int>(2, 4));	// ��� 2
	um[3] = 6;							// ��� 3

	print_umap1(um);

	cout << endl;

	// ���� ���� �޴� ���
	cout << "Ű�� 3�ΰ��� �� : ";
	print_key_as_value_map1(um, 3);

	cout << "Ű�� 3�ΰ��� �� : ";
	print_key_as_value_map2(um, 3);

	cout << um[3] << endl;
	cout << um[4] << endl;

	// ���� ���� �޴� ���
	cout << "Ű�� 4�ΰ��� �� : ";
	print_key_as_value_map1(um, 4);

	cout << "Ű�� 4�ΰ��� �� : ";
	print_key_as_value_map2(um, 4);

	// �ش� key�� ����
	um.erase(3);

	// count(): key�� ������ 1, ������ 0 ��ȯ
	if (um.count(3)) 
	{
		cout << "Ű 3�� ���� value�� ������" << endl;
	}
	else 
	{
		cout << "Ű 3�� ���� value�� �������� ����" << endl;
	}

	// ����� ���� ���� ��ȯ
	cout << "����� ���� ���� : " << um.size() << endl;

	// ��� ���� ����
	um.clear();

	// ��� �ִ��� Ȯ��
	if (um.empty()) 
	{
		cout << "���� �������" << endl;
	}
	else 
	{
		cout << "���� ������� ����" << endl;
	}

	// �ʿ� �����ϴ� ���
	um.insert({ 1, 3 });				// ��� 1
	um.insert(pair<int, int>(2, 4));	// ��� 2
	um[3] = 6;							// ��� 3
	um[4] = 8;							// ��� 3
	um[5] = 10;							// ��� 3
	um[6] = 12;							// ��� 3
	um[7] = 14;							// ��� 3

	//��� ���� �ؽ� ��Ŷ ���� ��ȯ
	cout << "��� ���� ��Ŷ�� ���� : " << um.bucket_count() << endl;
	//���� �ؽ� ���̺��� �������� ��ȯ(��� �� / ��Ŷ ��)
	cout << "������ : " << um.load_factor() << endl;

	//�ּ� n���� ��Ŷ�� �������� ���Ҵ�(���� ����ȭ)
	um.rehash(20);
	//��� ���� �ؽ� ��Ŷ ���� ��ȯ
	cout << "��� ���� ��Ŷ�� ���� : " << um.bucket_count() << endl;
	//���� �ؽ� ���̺��� �������� ��ȯ(��� �� / ��Ŷ ��)
	cout << "������ : " << um.load_factor() << endl;
}