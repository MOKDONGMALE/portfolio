using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;

public class csMemoList : MonoBehaviour
{
    public static string usingEmail = "test1"; // 내 아이디
    public string memolist; // memolist 전체 내역을 저장
    public static int memoCount; // memolist에 저장된 친구 수

    static string btnMemoName; // 버튼 텍스트에서 얻은 메모 이름
    public string friendNick; // memolist 테이블에서 불러올 ;를 붙인 친구 닉네임

    public string delMemoN;   // 지울 친구 닉네임


    void Start()
    {
        StartCoroutine(showMemoList()); // 시작하자마자 친구리스트가 뜸
        Invoke("showList", 1f); // 지연시키지 않으면 값이 list가 안뜸
    }


    public IEnumerator showMemoList()
    {
        WWWForm form = new WWWForm();
        form.AddField("email", usingEmail); // 내 아이디를 php로 보내기
        using (UnityWebRequest www = UnityWebRequest.Post("http://14.52.43.228:801/MemoList_S.php", form))
        {
            yield return www.SendWebRequest();

            if (www.isNetworkError || www.isHttpError)
            {
                Debug.Log("네트워크 에러:" + www.error);
            }
            else
            {
                memolist = www.downloadHandler.text; // friendlist 테이블에서 가져온 친구 닉네임들을 friendlist에 저장
            }

        }
    }

    public void showList()
    {
        string[] split_text = memolist.Split(';'); // ;를 기준으로 친구 나누기
        memoCount = split_text.Length - 1; // ;로 나눈 친구 수

        for (int i = 0; i < split_text.Length - 1; i++)
        {
            GameObject.Find("MemoName").transform.
                Find("btnMemo" + i.ToString()).gameObject.SetActive(true);  // btnFriend 버튼 활성화

        }
         
        for (int i = 0; i < split_text.Length - 1; i++)
        {
            GameObject.Find("btnMemo" + i).
                GetComponentInChildren<Text>().text = split_text[i]; // btnFriend 버튼에 할당된 친구 닉네임 가져오기
        }
    }


    //public void getDelFriendNick(Button button)
    //{
    //    delFriendN = button.GetComponentInChildren<Text>().text;
    //}


    //public void OnClicked(Button button)
    //{
    //    friendNick = delFriendN + ";"; // friendlsit에 있는 친구 닉네임을 찾기 위해 ;를 추가
    //    StartCoroutine(deleteFriend());
    //    SceneManager.LoadScene("FRIENDLIST"); // 친구 삭제되면 다시 씬을 로드
    //}

    //public IEnumerator deleteFriend()
    //{
    //    WWWForm form = new WWWForm();
    //    form.AddField("friendnickname", friendNick);
    //    using (UnityWebRequest www = UnityWebRequest.Post("http://localhost:800/DeleteFriend_S.php", form))
    //    {
    //        yield return www.SendWebRequest();

    //        if (www.isNetworkError || www.isHttpError)
    //        {
    //            Debug.Log("네트워크 에러:" + www.error);
    //        }
    //        else
    //        {
    //            Debug.Log(www.downloadHandler.text);
    //        }

    //    }
    //}
}


