//�Ե����� Ƽ���� ���α׷�

#include <stdio.h>
int main()
{
	int fullYear;	//�ֹι�ȣ���ڸ� 
	int frontYear; // �⵵ 
	int month; //���� 
	int day;
 	int temp; 	//�� ����� ���� ���� 
	int temp2;	//�� ����� ���� ����
	int realage; // ������ 
	int restart=0;	//�ݺ����� ���� ���� 
	int multiTicket;	// �̿�� ������ ���� ���� 
	int dayTicket;	//�ְ��� �߰��� ������ ���� ���� 
	int restart2=0;	//�ְ��� �߰��� ���ý� �ǵ����� ����. 
	int howMany = 0;	//Ƽ�� ���� ���ϴ� ����ǥ�⸦ ���� ����.
	int special;	//������ ������ ���� ����. 
	float price;	//�⺻ ���� 
	float result;	//���� ����� 
	int totalPrice;	//���� ���� 
	int keepgo;
	int reorder;	//�ֹ� ���� 1~10������� �Է� ����. 
	
	const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
		 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;

	const int MULTI_REAL_BABY_PRICE = 0,MULTI_BABY_PRICE = 15000,
		 MULTI_ADULT_DAY_PRICE = 59000, MULTI_ADULT_NIGHT_PRICE = 48000,
		 MULTI_TEEN_DAY_PRICE = 52000, MULTI_TEEN_NIGHT_PRICE = 42000,
		 MULTI_CHILD_DAY_PRICE = 47000, MULTI_CHILD_NIGHT_PRICE = 36000;
	
	const int PARK_REAL_BABY_PRICE = 0,PARK_BABY_PRICE = 15000,
		 PARK_ADULT_DAY_PRICE = 56000, PARK_ADULT_NIGHT_PRICE = 45000,
		 PARK_TEEN_DAY_PRICE = 50000, PARK_TEEN_NIGHT_PRICE = 40000,
		 PARK_CHILD_DAY_PRICE = 46000, PARK_CHILD_NIGHT_PRICE = 35000;
		 		 
	const float DISABLE_DISCOUNT_RATE = 0.6, MERIT_DISCOUNT_RATE = 0.5,
			MULTI_CHILD_DISCOUNT_RATE = 0.8,	PREGNANT_DISCOUNT_RATE = 0.85;
	
	
	
	while(restart==0)						//��ü �ݺ����� ���� Whild������ ����. 
	{
			
			printf("�̿���� �����ϼ���.\n");
			printf("1. �����̿��.\n");	
			printf("2. ��ũ�̿��.\n");	
			printf("3. Ƽ�� ���� ��ġ ����.\n");
			printf("=========================\n");
			scanf("%d",&multiTicket);	
			
		
		switch(multiTicket)
		{
			case 1:	//�����̿�� ���ý� 
			{
				while(restart2=0)
				printf("Ƽ�� ������ �����ϼ���.\n");
				printf("1. �ְ���.\n");	
				printf("2. �߰���.\n");	
				printf("3. Ƽ�� ���� ��ġ ����.\n");
				printf("=========================\n");
				scanf("%d",&dayTicket);
				switch(dayTicket)
				{
					case 1:	//�ְ��̿�� ���ý� 
					{
						printf("�ְ��̿���� ���̽��ϴ�.\n");
						printf("�ֹε�Ϲ�ȣ ���ڸ��� �Է��ϼ���.\n");
						printf("����:950505\n");
						scanf("%d",&fullYear); 	
						//2000 �����̸� �� �Ʒ������� 
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						//1900 ���� �⵵ ���ϱ� 
						else
						{
							frontYear = (fullYear+19000000)/10000;

							// ��,��¥ ���ϱ�
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						// ������ ����ϱ�. ����⵵ - ����. ���� �������� -1  �׳� ���� : ���� ���ϱ� 1 
						realage = 2022-frontYear;
						if(month<3)
						{
							realage = realage+1;
						} 
						else if(month==3)
						{
							if(day<=15)
							{
								realage = realage+1;
							}
							else
							{
								realage = realage-1;
							}
						}
						else if(month>3)
						{
							realage = realage-1;
						}
						// ���̿� ���� ���� ���ϱ� 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//���� 
						{price = MULTI_ADULT_DAY_PRICE;}
						else if(realage>MAX_ADULT)						//����  
						{price = MULTI_CHILD_DAY_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//�ʴ� 
						{price = MULTI_TEEN_DAY_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//���
						{price = MULTI_CHILD_DAY_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//������
						{price = MULTI_REAL_BABY_PRICE;} 
						printf("�� ���� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
						scanf("%d",&howMany);
						printf("�������� �����ϼ���.\n");
						printf("1.����(���� ���� �ڵ�ó���˴ϴ�.)\n");
						printf("2.�����\n");
						printf("3.����������\n");
						printf("4.���ڳ�\n");
						printf("5.�ӻ��\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("������ %d���Դϴ�.\n",totalPrice);	
						printf("�����մϴ�!\n");
						printf("��� �߱��Ͻðڽ��ϱ�?\n");
						printf("1.Ƽ��  �߱�\n");
						printf("2.�� ��\n");
						scanf("%d",&keepgo);
						if(keepgo==1)
						{
							restart=0;
						} 
						else if(keepgo==2)
						{
							restart=1;
						}
						restart2=1;
						break;
					}
					
					case 2:	//�߰��̿�� ���ý� 
					{
						printf("�߰��̿���� ���̽��ϴ�.\n");
						printf("�ֹε�Ϲ�ȣ ���ڸ��� �Է��ϼ���.\n");
						printf("����:950505\n");
						scanf("%d",&fullYear); 	
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						} 
						else
						{
							frontYear = (fullYear+19000000)/10000;
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						realage = 2022-frontYear;
						if(month<3)
						{
							realage = realage+1;
						} 
						else if(month==3)
						{
							if(day<=15)
							{
								realage = realage+1;
							}
							else
							{
								realage = realage-1;
							}
						}
						else if(month>3)
						{
							realage = realage-1;
						}
						// ���̿� ���� ���� ���ϱ� 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//���� 
						{price = MULTI_ADULT_NIGHT_PRICE;}
						else if(realage>MAX_ADULT)						//����  
						{price = MULTI_CHILD_NIGHT_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//�ʴ� 
						{price = MULTI_TEEN_NIGHT_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//���
						{price = MULTI_CHILD_NIGHT_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//������
						{price = MULTI_REAL_BABY_PRICE;}  				
						printf("�� ���� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
						scanf("%d",&howMany);
						printf("�������� �����ϼ���.\n");
						printf("1.����(���� ���� �ڵ�ó���˴ϴ�.)\n");
						printf("2.�����\n");
						printf("3.����������\n");
						printf("4.���ڳ�\n");
						printf("5.�ӻ��\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("������ %d���Դϴ�.\n",totalPrice);		
						printf("�����մϴ�!\n");				
						restart2=1;
						break;
					}
					
					case 3:	//Ƽ�� ���Ÿ� ������ ������
					{
						restart2=1;
						restart=1;
						break;
					}
					
					default :	//�߸� ������ ��
					{
						printf("�߸��Է��ϼ̽��ϴ�.ó������ ���ư��ϴ�.\n");
						restart2=0;
						break; 
					} 
				}
				break;
			}
			
			case 2:	//��ũ�̿�� ���ý� 
			{			
				while(restart2=0)
				printf("Ƽ�� ������ �����ϼ���.\n");
				printf("1. �ְ���.\n");	
				printf("2. �߰���.\n");	
				printf("3. Ƽ�� ���� ��ġ ����.\n");
				printf("=========================\n");
				scanf("%d",&dayTicket);
				switch(dayTicket)
				{
					case 1:	//�ְ��̿�� ���ý� 
					{
						printf("�ְ��̿���� ���̽��ϴ�.\n");
						printf("�ֹε�Ϲ�ȣ ���ڸ��� �Է��ϼ���.\n");
						printf("����:950505\n");
						scanf("%d",&fullYear); 	
						//2000 �����̸� �� �Ʒ������� 
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						//1900 ���� �⵵ ���ϱ� 
						else
						{
							frontYear = (fullYear+19000000)/10000;

							// ��,��¥ ���ϱ�
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						// ������ ����ϱ�. ����⵵ - ����. ���� �������� -1  �׳� ���� : ���� ���ϱ� 1 
						realage = 2022-frontYear;
						if(month<3)
						{
							realage = realage+1;
						} 
						else if(month==3)
						{
							if(day<=15)
							{
								realage = realage+1;
							}
							else
							{
								realage = realage-1;
							}
						}
						else if(month>3)
						{
							realage = realage-1;
						}
						// ���̿� ���� ���� ���ϱ� 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//���� 
						{price = PARK_ADULT_DAY_PRICE;}
						else if(realage>MAX_ADULT)						//����  
						{price = PARK_CHILD_DAY_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//�ʴ� 
						{price = PARK_TEEN_DAY_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//���
						{price = PARK_CHILD_DAY_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//������
						{price = PARK_REAL_BABY_PRICE;} 
							
						printf("�� ���� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
						scanf("%d",&howMany);
						printf("�������� �����ϼ���.\n");
						printf("1.����(���� ���� �ڵ�ó���˴ϴ�.)\n");
						printf("2.�����\n");
						printf("3.����������\n");
						printf("4.���ڳ�\n");
						printf("5.�ӻ��\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("������ %d���Դϴ�.\n",totalPrice);	
						printf("�����մϴ�!\n");
						restart2=1;
						break;
					}
						
					
					case 2:	//�߰��̿�� ���ý� 
					{
						printf("�߰��̿���� ���̽��ϴ�.\n");
						printf("�ֹε�Ϲ�ȣ ���ڸ��� �Է��ϼ���.\n");
						printf("����:950505\n");
						scanf("%d",&fullYear); 	
						temp = fullYear+1000000;
	 
						if(1000101<=temp&&temp<=1220316)
						{
							frontYear = (fullYear+20000000)/10000;

							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						} 
						else
						{
							frontYear = (fullYear+19000000)/10000;
							temp2 = (fullYear/100)*100;
							day = fullYear-temp2;
							temp2 = (fullYear/10000)*10000;
							month = (fullYear - temp2 - day)/100;
						}
						realage = 2022-frontYear;
						if(month<3)
						{
							realage = realage+1;
						} 
						else if(month==3)
						{
							if(day<=15)
							{
								realage = realage+1;
							}
							else
							{
								realage = realage-1;
							}
						}
						else if(month>3)
						{
							realage = realage-1;
						}
						// ���̿� ���� ���� ���ϱ� 
						if(realage<=MAX_ADULT&&realage>=MIN_ADULT)		//���� 
						{price = PARK_ADULT_NIGHT_PRICE;}
						else if(realage>MAX_ADULT)						//����  
						{price = PARK_CHILD_NIGHT_PRICE;}
						else if(realage>=MIN_TEEN&&realage<=MAX_TEEN)	//�ʴ� 
						{price = PARK_TEEN_NIGHT_PRICE;}
						else if(realage>=MIN_CHILD&&realage<=MAX_CHILD)	//���
						{price = PARK_CHILD_NIGHT_PRICE;} 
						else if(realage>=MIN_BABY&&realage<MIN_CHILD)	//������
						{price = PARK_REAL_BABY_PRICE;}  			
						printf("�� ���� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
						scanf("%d",&howMany);	
						printf("�������� �����ϼ���.\n");
						printf("1.����(���� ���� �ڵ�ó���˴ϴ�.)\n");
						printf("2.�����\n");
						printf("3.����������\n");
						printf("4.���ڳ�\n");
						printf("5.�ӻ��\n");
						scanf("%d",&special);
						if(special==1)
						{
							result = price * 1;
						}
						else if(special==2)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;	
							}
							else{	result = price * DISABLE_DISCOUNT_RATE;	}
						}
						else if(special==3)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MERIT_DISCOUNT_RATE;	}
						}
						else if(special==4)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * MULTI_CHILD_DISCOUNT_RATE;	}
						}
						else if(special==5)
						{
							if(realage>MAX_ADULT)
							{	
								result = price * 1;
							}
							else{	result = price * PREGNANT_DISCOUNT_RATE;	}
						}
						totalPrice = result * howMany;
						printf("������ %d���Դϴ�.\n",totalPrice);		
						printf("�����մϴ�!\n");				
						restart2=1;
						break;
					}
					
					case 3:	//Ƽ�� ���Ÿ� ������ ������
					{
						restart2=1;
						restart=1;
						break;
					}
					
					default :	//�߸� ������ ��
					{
						printf("�߸��Է��ϼ̽��ϴ�.ó������ ���ư��ϴ�.\n");
						restart2=0;
						break; 
					} 
				}	
				break;
			}
			case 3:
			{	
				restart=1;
				break; 
			}	
			
			default :	//�� �� �Է½� 
			{
				printf("�߸��Է��ϼ̽��ϴ�."); 
				break;
			}
			
		}
	}
	
	return 0;
}
