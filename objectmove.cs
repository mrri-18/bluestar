using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playermove : MonoBehaviour
{
    public float speed = 5;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical"); //w(��),s(�Ʒ�)�� ����
        //�� ��� a(-1),d(1)�� ���� 
        //right: [0,0,0], [1,0,0], [-1,0,0],
        //up: [0,0,0], [0,1,0], [0,-1,0],
        Vector3 dir = Vector3.right * h + Vector3.up * v;

        dir.Normalize();//���͸� ����ȭ(���̸� 1�� �������.)
        transform.position = transform.position + dir * speed * Time.deltaTime;
    }
}
