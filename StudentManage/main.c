#include "Manager.h"	 //�Զ���ͷ�ļ�,�������ʵ�ֹ��ܵĺ���.

int main(viod)
{
	char chooseSave;
	int flag;

	initilization();	 //��ʼ��

	while (1)			 //������Ϊ1����ѭ��������һ�����Կ��Ƶ��ظ�����
	{
		do
		{
			printf("\n");
			printf("\t === ѧ����Ϣ����ϵͳ ===\n\n");
			printf("\t ========= �˵� =========\n\n");
			printf("\t�鿴��Ϣ ���������������� 1\n\n");
			printf("\t�����Ϣ ���������������� 2\n\n");
			printf("\t�޸���Ϣ ���������������� 3\n\n");
			printf("\tɾ����Ϣ ���������������� 4\n\n");
			printf("\t��ѯ��Ϣ (ѧ��)  �������� 5\n\n");
			printf("\t��ѯ��Ϣ (����)  �������� 6\n\n");
			printf("\t��ѧ�Ŵ�С���������� ���� 7\n\n");
			printf("\t���浽�ļ� �������������� 8\n\n");
			printf("\t�˳����� ���������������� 0\n\n");
			printf("\tѡ��:");
			scanf("%d", &flag);
		} while (flag<0 || flag>8); //���ǲ˵��е�ѡ��������ʾ�˵�

		switch (flag)
		{
		case 0:
			if (editFlag != 0) 				 //���������޸ģ�ѯ���Ƿ񱣴�
			{
				system("cls");
				printf("\n\t�޸ĺ���ļ�û�б���,�Ƿ񱣴�(Y/N):");
				scanf("%s", &chooseSave);
				switch (chooseSave)
				{
				case 'Y':
				case 'y':
					save(head);
					exit(0);	//������ʹ��return 0;�ᵼ��chooseSave���
				case 'N':
				case 'n':
					system("cls");
					printf("\n\t�����˳�����.");
					system("pause");
					exit (0);
					break;
				default:
					system("cls");  //�����Ļ�ϵ�����
					printf("\n\t ��ѡ����ȷ�Ĳ���,");
					system("pause");
					system("cls");  //�����Ļ�ϵ�����
					break;
				}
			}
			else			//���û���������޸ľ�ֱ���˳�
				return 0;	//��������ʹ�� return �����˳�����, exit(0) �������κεط��˳�����
			break;
		case 1:
			printList(head);
			break;
		case 2:
			addList(head);
			break;
		case 3:
			modify(head);
			break;
		case 4:
			delList(head);
			break;
		case 5:
			searchNum(head);
			break;
		case 6:
			searchName(head);
			break;
		case 7:
			BubbleShortList_1(head);
			break;
		case 8:
			save(head);
			break;
		default:
			system("cls");  //�����Ļ�ϵ�����
			printf("\n\t ��ѡ����ȷ�Ĳ���,");
			system("pause");
			system("cls");  //�����Ļ�ϵ�����
		}
	}
}