using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class csBtnSetting : MonoBehaviour
{

    private void Start()
    {
        StartCoroutine(Entity.getValue("http://14.52.43.228:801/CountEverythings.php"));

    }


}
