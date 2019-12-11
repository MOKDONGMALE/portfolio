using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MemoList : MonoBehaviour
{
    private void Start()
    {
        //StartCoroutine(Entity.GetServer());   //서버연결
        StartCoroutine(Entity.CountMemoNum("http://14.52.43.228:801/MemoCount.php", "email", csUIL.testEmail.ToString()));
    }
}
