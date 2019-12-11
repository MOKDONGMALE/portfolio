using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;

public class csInvite : MonoBehaviour
{
    public static string usingEmail = "hsy4988@naver.com"; // 내 아이디
    public InputField friendEmail; // 초대할 친구 아이디
    public string f_nickname; // userinfo 테이블에서 가져올 친구 닉네임
    public string primary; // friendlist 테이블 PRIMARY 칼럼에 저장
    public int f_num = 1; //friendlist 테이블 FRIENDNUM 칼럼에 저장

    public string friendlist; // friendlist 전체 내역을 저장
    public static int friendCount; // friendlist에 저장된 친구 수

    static string btnName; // 버튼에 나타난 친구 닉네임 저장

    void Start()
    {
        StartCoroutine(showFriendList());
        Invoke("showList", 1f); // 시작하자마자 친구리스트 보여줌
    }

    public IEnumerator showFriendList()
    {
        WWWForm form = new WWWForm();
        form.AddField("email", usingEmail); // 내 아이디를 php로 보내기
        using (UnityWebRequest www = UnityWebRequest.Post("http://14.52.43.228:800/FriendList_S.php", form))
        {
            yield return www.SendWebRequest();

            if (www.isNetworkError || www.isHttpError)
            {
                Debug.Log("네트워크 에러:" + www.error);
            }
            else
            {
                friendlist = www.downloadHandler.text; // friendlist 테이블에서 가져온 친구 닉네임들을 friendlist에 저장
            }
        }
    }

    public void showList()
    {
        string[] split_text = friendlist.Split(';'); // ;를 기준으로 친구 나누기
        friendCount = split_text.Length - 1; // ;로 나눈 친구 수

        for (int i = 0; i < friendCount; i++)
        {
            GameObject.Find("FriendNickname").transform.
                Find("btnFriend" + i.ToString()).gameObject.SetActive(true);    // btnFriend 버튼 활성화

        }

        for (int i = 0; i < friendCount; i++)
        {
            GameObject.Find("btnFriend" + i).
                GetComponentInChildren<Text>().text = split_text[i]; // btnFriend 버튼에 할당된 친구 닉네임 가져오기
        }
    }


    public IEnumerator checkUser()
    {
        WWWForm form = new WWWForm();
        form.AddField("email", friendEmail.text); // InputField에서 받은 친구 이메일을 php로 보내기
        using (UnityWebRequest www = UnityWebRequest.Post("http://localhost:800/GetFriendNickname_S.php", form))
        {
            yield return www.SendWebRequest();

            if (www.isNetworkError || www.isHttpError)
            {
                Debug.Log("네트워크 에러:" + www.error);
            }
            else
            {
                f_nickname = www.downloadHandler.text;  // userinfo에서 가져온 친구 닉네임 f_nickname에 저장
            }

        }
    }


    public IEnumerator saveFriend()
    {
        primary = usingEmail + friendEmail.text;
        WWWForm form = new WWWForm();
        form.AddField("primary", primary);
        form.AddField("email", usingEmail);
        form.AddField("friendemail", friendEmail.text);
        form.AddField("friendnickname", f_nickname + ";");
        form.AddField("num", f_num);
        using (UnityWebRequest www = UnityWebRequest.Post("http://localhost:800/AddFriendList_S.php", form))
        {
            yield return www.SendWebRequest();

            if (www.isNetworkError || www.isHttpError)
            {
                Debug.Log("네트워크 에러:" + www.error);
            }
            else
            {
                //Debug.Log(www.downloadHandler.text);
            }
        }
    }

    public void valChangeFriendemail()
    {
        StartCoroutine(checkUser()); // userinfo에서 추가할 친구의 nickname만 받아와
    }

    public void btnAddFriend() // 친구 추가 버튼 클릭 시
    {
        StartCoroutine(saveFriend());
        f_num += f_num;
    }

    public void OnClicked(Button button)    // 친구 닉네임 클릭 시 초대방으로 넘어감
    {
        btnName = button.GetComponentInChildren<Text>().text;
        SceneManager.LoadScene("MULTIPLE");
    }
}
