using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playermove : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //c# 물체 이동하기
        transform.position = transform.position + Vector3.down * 5 * Time.deltaTime;
    }
}
