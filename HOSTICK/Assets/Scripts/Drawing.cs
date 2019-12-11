﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.Runtime.Serialization;
using System;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;



public class Drawing : MonoBehaviour
{
    bool isLoadLineEnd = false;

    int colorCnt = 0;
    int sizeCnt = 0;
    //색깔이나 글자 굵기를 지정해놓은 숫자
    private Plane objPlane;
    //3D 공간에서 평면 표현, 원근이 적용되게 설정

    Color colorFromUI;
    float sizeFromUI;
    //색깔과 글자 굵기 형태 지정
    //int listCnt = 0;
    //static bool drawing;
    private bool isClick = false;
    private bool isFirst = true;

    private LineRenderer line;
    private List<LineRenderer> listLine = new List<LineRenderer>();

    private GameObject lineObject;
    private List<GameObject> lineList = new List<GameObject>();

    public GameObject Draw;


    float checkCor = 0f;
    int cnt = 0;

    int loadcnt = 0;

    public static bool checkedPanel;
    private int pointIndex;

    [Header("database")]
    
    int updatenum =1;


    public static int dataCnt = 0;
    int orderNum = 0;

    public InputField MemoName;

    public void ChangeColor()
    {
        colorCnt++;
        if (colorCnt == 3)
        {
            colorCnt = 0;
        }
    }
    public void ChangeSize()
    {
        sizeCnt++;
        if (sizeCnt == 3)
        {
            sizeCnt = 0;
        }
    }

    public void btnCloseDrawPanel()
    {
        if (Drawing.checkedPanel == true)
        {
            Draw.SetActive(false);
        }
    }

    public void StartLine()
    {
        if (isFirst)
        {
            
            if ((Input.touchCount > 0 &&
                 Input.GetTouch(0).phase == TouchPhase.Moved) //모바일에서 동작 하는 것 -> TouchPhase.Moved : 터치 움직임
                || Input.GetMouseButton(0)) // 스크린에서 동작 하는 것 => GetMouseButton : 마우스 움직임
            {
                Draw.SetActive(false);
                isClick = true;
                isFirst = false;
                objPlane = new Plane(Camera.main.transform.forward * -1, this.transform.position);
                Ray mRay = Camera.main.ScreenPointToRay(Input.mousePosition);
                float rayDistance;
                //raycast 거리변수 선언
                if (objPlane.Raycast(mRay, out rayDistance))
                {
                    this.transform.position = mRay.GetPoint(rayDistance);
                }
                CreateLineObject();
            }
        }
    }

    public void EndLine()
    {
        if ((Input.touchCount > 0 && Input.GetTouch(0).phase == TouchPhase.Ended) || Input.GetMouseButtonUp(0))
        {
            listLine.Add(line);
            listLine[cnt] = line;

            lineList.Add(lineObject);
            lineList[cnt] = lineObject;
            cnt++;
            isFirst = true;
            isClick = false;
        }
    }
    public void Start()
    {
        StartCoroutine(Entity.GETGPS("http://14.52.43.228:801/PublicMemoLoad.php", "email", "MLati", "MLongit", csUIL.testEmail.ToString(), MyGPS.lati, MyGPS.longi));
    }


    void Update()
    {
        
        if (sizeCnt == 0)
        {
            sizeFromUI = 0.001f;
        }
        else if (sizeCnt == 1)
        {
            sizeFromUI = 0.005f;
        }
        else if (sizeCnt == 2)
        {
            sizeFromUI = 0.01f;
        }

        if (colorCnt == 0)
        {
            colorFromUI = Color.black;
        }
        else if (colorCnt == 1)
        {
            colorFromUI = Color.white;
        }
        else if (colorCnt == 2)
        {
            colorFromUI = Color.red;
        }

        if (isClick)
        {
            if ((Input.touchCount > 0 &&
                    Input.GetTouch(0).phase == TouchPhase.Moved) //모바일에서 동작 하는 것 -> TouchPhase.Moved : 터치 움직임
                   || Input.GetMouseButton(0)) // 스크린에서 동작 하는 것 => GetMouseButton : 마우스 움직임
            {
                objPlane = new Plane(Camera.main.transform.forward * -1, this.transform.position);
                Ray mRay = Camera.main.ScreenPointToRay(Input.mousePosition);
                float rayDistance;
                //raycast 거리변수 선언
                if (objPlane.Raycast(mRay, out rayDistance))
                {
                    this.transform.position = mRay.GetPoint(rayDistance);
                }
                
            }
            Debug.Log("Move");
            Vector3 position = this.transform.position;

            if ((position.x != line.GetPosition(pointIndex).x) ||
                (position.y != line.GetPosition(pointIndex).y) ||
                (position.z != line.GetPosition(pointIndex).z))
            {
                //라인렌더러의 노드 갯수를 증가
                ++line.positionCount;
                //새로 만든 노드의 위치값을 설정
                line.SetPosition(line.positionCount - 1, position);
                pointIndex = line.positionCount - 1;
            }
        }

    }
    public void GPSLoad()
    {
        StartCoroutine(Entity.GETGPS("http://14.52.43.228:801/PublicMemoLoad.php", "email", "MLati", "MLongit", csUIL.testEmail.ToString(), MyGPS.lati, MyGPS.longi));
    }

    public void Eraser()    //지우기 버튼을 클릭시 Line을 지우는것
    {
        try //listLine을 관리하기 위해서 try catch문을 사용
        {
            // 실행하고자 하는 문장들
            if (listLine != null && listLine.Count > 0) //Stroke가 존재하고 개수가 0개 이상일때만 작동하도록
            {
                Destroy(listLine[cnt - 1]);   //cnt의 값이 ++됨으로 하나를 빼준 Stroke 값을 제거해준다                
                Destroy(lineList[cnt - 1]);
                cnt--;  //List의 stroke가 지워졌으므로 값을 cnt값을 감소시킨다.
            }
        }
        catch (System.Exception ex) //Stroke가 더이상 하이라키에 없을때 실행된다
        {
            Debug.Log("더이상 지울것이 없습니다." + ex);    //오류구문이 없으면 Exception오류가 발생하게 됩니다.
            cnt = 0;    //cnt = 0을 초기화 안시켜주면 계속해서 증가하기 때문에 아예 없을때 0으로 초기화 시켜준다.
        }
    }
 
    void CreateLineObject(LineRenderer line, Vector3 position, Material mt, float width)
    {
        line.material.color = mt.color;
        line.useWorldSpace = false;

        //라인의 끝부분을 부드럽게 하기위한 버텍스 갯수 설정
        line.numCornerVertices = 10;

        //라인렌더러의 폭 설정
        line.widthMultiplier = width;

        //라인렌더러의 노드 갯수를 1로 설정
        line.positionCount = 1;

        line.SetPosition(0, position);
        line.sortingOrder = orderNum++;
    }

    public void btnMemoNum()
    {
        Debug.Log(Entity.memoArray[0]);
        Debug.Log("memonum:" + Entity.memoCount);
    }

    void CreateLineObject()
    {
        //라인렌더러를 추가할 게임오브젝트를 생성
        GameObject lineObject = new GameObject("Line");
        line = lineObject.AddComponent<LineRenderer>();
        line.material.color = colorFromUI;
        line.useWorldSpace = false;

        //라인의 끝부분을 부드럽게 하기위한 버텍스 갯수 설정
        line.numCornerVertices = 20;

        //라인렌더러의 폭 설정
        line.widthMultiplier = sizeFromUI;

        //라인렌더러의 노드 갯수를 1로 설정
        line.positionCount = 1;
        pointIndex = line.positionCount - 1;

        //첫 번째 노드의 위치를 컨트롤러의 위치로 설정
        Vector3 position = this.transform.position;

        line.SetPosition(0, position);
        line.sortingOrder = orderNum++;
    }
    public int lineSequence =0;
    public int lineNumber;
    public int PointNum = 0;

    public int testlinenum;

    public static int memonum;

    public void SaveLineTextAll()
    {
        
        Debug.Log("지금메모넘버:" + Entity.memoCount);
        memonum = Entity.memoCount;
        Debug.Log("최오종메모넘버:" + memonum);
        StartCoroutine(Entity.SaveMemo("http://14.52.43.228:801/MemoSave.php", "KeyValue", "email", "memoType", "lati", "longit", "memoName",csUIL.testEmail.ToString()+ memonum.ToString(),csUIL.testEmail.ToString(), csUIL.MemoType.ToString(), MyGPS.lati, MyGPS.longi, MemoName.text));
        Debug.Log("email:" + csUIL.testEmail);
        Debug.Log("memoType:" + csUIL.MemoType);
        Debug.Log("memoName:" + MemoName.text);
        
        foreach (LineRenderer _line in listLine)
        {
            if (_line != null)
            {
                Entity.temptest++;
                Vector3[] posArray = new Vector3[_line.positionCount];
                string strColor = string.Format("{0},{1},{2},{3}", _line.material.color.r, _line.material.color.g, _line.material.color.b, _line.material.color.a);

                StartCoroutine(Entity.SaveLine("http://14.52.43.228:801/LineSave.php", "LineSequence", "KeyValue", "LineNumber", "Colour", "Size",
                   Entity.temptest, csUIL.testEmail.ToString() + memonum.ToString(), lineNumber.ToString(), strColor, _line.widthMultiplier.ToString()));
               
                for (int i = 0; i<_line.positionCount; i++)
                {
                    posArray[i] = _line.GetPosition(i);
                    StartCoroutine(Entity.SaveLinePoint("http://14.52.43.228:801/SavePoint.php", "PointNumber", "LineSequence", "PosX", "PosY", "PosZ",
                       Entity.countPointNum.ToString(), Entity.temptest.ToString(), posArray[i].x.ToString(), posArray[i].y.ToString(), posArray[i].z.ToString()));
                    PointNum++;
                    Entity.countPointNum++;
                }
                lineNumber++;
                lineSequence++;
            }
            else
            {
                Debug.Log("null");
            }
        }
        memonum++;
       
        lineNumber = 0;
    }

    IEnumerator CoCheckLoadLine()
    {
        while (true)
        {
            if (Entity.isLoadLine == false)
            {
                yield return new WaitForSeconds(0.01f);
            }
            else
            {
                //라인렌더러를 추가할 게임오브젝트를 생성            
                GameObject lineObject = new GameObject("Line");
                line = lineObject.AddComponent<LineRenderer>();

                Vector3 pos = new Vector3();
                pos.x = float.Parse(Entity.points[0]);
                pos.y = float.Parse(Entity.points[1]);
                pos.z = float.Parse(Entity.points[2]);

                string colorR = Entity.colorSizeCnt[0]; 
                string colorG = Entity.colorSizeCnt[1];
                string colorB = Entity.colorSizeCnt[2];
                string colorA = Entity.colorSizeCnt[3];
                Color changeColor = new Color(float.Parse(colorR), float.Parse(colorG), float.Parse(colorB), float.Parse(colorA));//0001 RGBA -> "0,0,0,1" 이렇게 나와야한다 이게 문자열이라는 점...
                //하나로 합친 값이 나오기 때문에 Split해줘야 한다
                line.material.color = changeColor;
                //작동합니다. 정적 클래스에서 정적 함수를 선언하는 것은
                //중복된다는 경고 메시지가 표시되지만 명확성을 위해 그대로 두는 것이 좋습니다. 유해한 경고가 아닙니다.
                float width = float.Parse(Entity.colorSizeCnt[4]);
                
                CreateLineObject(line, pos, line.material, width);
                Debug.Log(Entity.points.Length + " CreateLineObject");
                for (int j = 3; j < (Entity.points.Length)-3; j = j + 3)
                {
                    Debug.Log(j + " Add Position");
                    pos.x = float.Parse(Entity.points[j]);
                    pos.y = float.Parse(Entity.points[j + 1]);
                    pos.z = float.Parse(Entity.points[j + 2]);
                    Debug.Log(pos.x);
                    Debug.Log(pos.y);
                    Debug.Log(pos.z);

                    ++line.positionCount;
                    line.SetPosition(line.positionCount - 1, pos);
                }
                iCnt++;
                listLine.Add(line);
                Debug.Log(iCnt + " End");
                
                break;
            }
        }
        isLoadLineEnd = true;
    }

    IEnumerator coLoadLineAll()
    {
        listLine.Clear();
        while (true)
        {
            if (iCnt >= Entity.GcountLineSeq)
            {
                iCnt = 0;
                Debug.Log("---End All Line---");
                break;
            }
            isLoadLineEnd = false;      //가져온 데이터를 다 그렸을 때
            Entity.isLoadLine = false;  //Entity.lineSEL 함수가 데이터를 가져왔을 때 사용
            
            Debug.Log(iCnt + " Start");

            Debug.Log("countLineSeq:" + Entity.GcountLineSeq);
            
            StartCoroutine(Entity.getColorSize("http://14.52.43.228:801/Colour.php", "LineSequence", Entity.GLineSequence[iCnt]));
            StartCoroutine(Entity.getPoint("http://14.52.43.228:801/GetPublicLinePoint.php", "LineSequence", Entity.GLineSequence[iCnt]));
            Debug.Log("ICNT 여기다:" + iCnt);
            StartCoroutine(CoCheckLoadLine());
            
            while (isLoadLineEnd == false)
            {
                yield return new WaitForSeconds(0.01f);
            }
        }
    }
    int iCnt = 0 ;
    public void LoadLineTextAll()
    {
        StartCoroutine(coLoadLineAll());
    }
}