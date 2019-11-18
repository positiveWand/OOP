//
// Created by 김혁진 on 2019/11/12.
//

#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include <iostream>

int main() {
    // 이번 과제는 테스트 코드를 주지 않습니다.
    // 직접 코드를 작성해보면서 확인해보세요
    {
        Number *a = new Integer(13);
        Number *result = a->add(new Float(3.14));

        std::cout << dynamic_cast<Float *>(result)->val() << std::endl; // 16.14
    }
    {
        Number *a = new Integer(3);
        Number *result = a
                ->add(new Float(3.14))
                ->sub(new Integer(1))
                ->mul(new Integer(7))
                ->sub(new Complex(11, 5));

        std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 24.980000 - 5.000000i
    }
    // 테스트 코드 작성해보고 확인해보세요
    // 채점은 임의의 테스트코드로 진행할 예정입니다
	{
		Number *aNum = new Integer(5);
		Number *bNum = new Integer("-35");

		Integer *aInt = dynamic_cast<Integer*>(aNum);
		Integer *bInt = dynamic_cast<Integer*>(bNum);

		bool pass = true;

		if(aInt->val() != 5)
			pass = false;
		if(bInt->val() != -35)
			pass = false;

		aInt->set_val(45);

		if(aInt->val() != 45)
			pass = false;
		if(aInt->types() != 0 || bInt->types() != 0)
			pass = false;
		//std::cout << aInt->to_string() << " " << bInt->to_string() << std::endl;

		std::cout << (pass ? "Integer기본 테스트 통과" : "Integer기본 테스트 실패") << std::endl;
	}
	{
		Number *aNum = new Float(3.14);
		Number *bNum = new Float("-2.714");

		Float *aFloat = dynamic_cast<Float*>(aNum);
		Float *bFloat = dynamic_cast<Float*>(bNum);

		bool pass = true;

		if(aFloat->val() != 3.14)
			pass = false;
		if(bFloat->val() != -2.714)
			pass = false;

		aFloat->set_val(6.28);

		if(aFloat->val() != 6.28)
			pass = false;
		if(aFloat->types() != 1 || bFloat->types() != 1)
			pass = false;
		//std::cout << aFloat->to_string() << " " << bFloat->to_string() << std::endl;

		std::cout << (pass ? "Float기본 테스트 통과" : "Float기본 테스트 실패") << std::endl;
	}
	{
		Number *aNum = new Complex(-1, 2);
		Number *bNum = new Complex(3.14, -34);

		Complex *aCom = dynamic_cast<Complex*>(aNum);
		Complex *bCom = dynamic_cast<Complex*>(bNum);

		bool pass = true;

		if(aCom->real() != -1 || aCom->imag() != 2)
			pass = false;

		if(bCom->real() != 3.14 || bCom->imag() != -34) {
			std::cout << bCom->real() << " " << bCom->imag() << std::endl;
			pass = false;
		}

		aCom->set_val(-2, 1);

		if(aCom->val().first != -2 || aCom->val().second != 1)
			pass = false;

		bCom->set_val(std::make_pair(34, -3.21));
		
		if(bCom->val().first != 34 || bCom->val().second != -3.21)
			pass = false;

		if(aCom->types() != 2 || bCom->types() != 2)
			pass = false;

		//std::cout << aCom->to_string() << " " << bCom->to_string() << std::endl;
		std::cout << (pass ? "Complex기본 테스트 통과" : "Complex기본 테스트 실패") << std::endl;
	}
	{
		Number* a = new Integer(3);
		Number* b = new Float(3.4);
		Number* i = a->add(b);

		Number* c = new Float(4.5);
		Number* d = new Integer(5);
		Number* j = c->add(d);

		//std::cout << b->to_string() << std::endl;
	}

	return 0;
}
