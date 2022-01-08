#include <afxwin.h>
#include <afxcmn.h>
#include "resource.h"

//#include <SDL.h>
//#include <SDL_audio.h>
#include <queue>
#include <cmath>
#include <MMSystem.h>
#include<Windows.h>
#include "EASendMailObj.tlh"

#include <tchar.h>
#include <atlbase.h>
#include <atlcom.h>
#include <atlstr.h>


using namespace EASendMailObjLib;
// Globals

CEdit* pName;
CSliderCtrl* pWetness;
CSliderCtrl* pAge;
CSliderCtrl* pPower;
CEdit* pEmailaddr;
CButton* pGenerate;
CButton* pSendemail;
CButton* pCancell;
CButton* phappy;
CButton* pSad;
CButton* pAgr;
CButton* pPrs;
CButton* pTired;
//CStatic* pHappy;





class Farty : public CDialog
{
public:
	int imood = 1;
	int iWetness = 1;
	int iPower = 1;
	int iAge = 1;
	const int ConnectNormal = 0;
	const int ConnectSSLAuto = 1;
	const int ConnectSTARTTLS = 2;
	const int ConnectDirectSSL = 3;
	const int ConnectTryTLS = 4;
	Farty(CWnd* pParent = NULL) : CDialog(Farty::IDD, pParent)
	{}
	enum { IDD = IDD_DIALOG_FartMaker };
protected:
	virtual void DoDataExchange(CDataExchange* pDX) {
		CDialog::DoDataExchange(pDX); 
	}

	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();

		pName = (CEdit*)GetDlgItem(IDC_EDIT_FartName);
		pWetness = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_Wetness);
		pAge = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_Age);
		pPower = (CSliderCtrl*)GetDlgItem(IDC_SLIDERPower);
		pEmailaddr = (CEdit*)GetDlgItem(IDC_EDIT2);
		pGenerate = (CButton*)GetDlgItem(IDC_BUTTON_Generate);
		pCancell = (CButton*)GetDlgItem(IDCANCEL);
		pSendemail = (CButton*)GetDlgItem(IDC_BUTTON1);
		phappy = (CButton*)GetDlgItem(IDC_RADIO_happy);
		pSad = (CButton*)GetDlgItem(IDC_RADIO_sad);
		pAgr = (CButton*)GetDlgItem(IDC_RADIO_aggr);
		pPrs = (CButton*)GetDlgItem(IDC_RADIO_pres);
		pTired = (CButton*)GetDlgItem(IDC_RADIO_tiered);



		
		pEmailaddr->SetWindowText(L"farter@farters.com");
		pName->SetWindowText(L"Black panter");
		HICON Icon1;
		Icon1 = LoadIcon(NULL ,MAKEINTRESOURCE(IDI_ASTERISK));
		SetIcon(Icon1, TRUE);


		phappy->SetCheck(true);
		pPower->SetPos(1);
		pPower->SetRange(1,5);
		pPower->SetTic(5);
		pPower->SetSelection(1,5);
		
		pWetness->SetPos(1);
		pWetness->SetRange(1, 3);
		pWetness->SetTic(3);
		pWetness->SetSelection(1, 3);

		pAge->SetPos(1);
		pAge->SetRange(1, 3);
		pAge->SetTic(3);
		pAge->SetSelection(1, 3);
	
		//HICON Icon1;
		//Icon1 = LoadIcon(NULL, MAKEINTRESOURCE(IDI_QUESTION));

		//pMood->SetColumnWidth(4, LVSCW_AUTOSIZE);

		
		

		return true;

	}
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedRadiohappy();
	afx_msg void OnBnClickedRadiosad();
	afx_msg void OnBnClickedRadioaggr();
	afx_msg void OnBnClickedRadiotiered();
	afx_msg void OnBnClickedRadiopres();
	afx_msg void OnNMReleasedcaptureSliderWetness(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMReleasedcaptureSliderAge(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMReleasedcaptureSliderpower(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonGenerate();
	afx_msg void OnBnClickedButton1();
};

class Thefarter: public CWinApp
{
public:
	Thefarter() {};
	virtual BOOL InitInstance()
	{
		CWinApp::InitInstance();
		SetRegistryKey(_T("Fart loudly"));
		Farty dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		return FALSE ;
	}
};


BEGIN_MESSAGE_MAP(Farty, CDialog)
	ON_EN_CHANGE(IDD_DIALOG_FartMaker, &Farty::OnEnChangeEdit1)
		ON_BN_CLICKED(IDC_RADIO_happy, &Farty::OnBnClickedRadiohappy)
	ON_BN_CLICKED(IDC_RADIO_sad, &Farty::OnBnClickedRadiosad)
	ON_BN_CLICKED(IDC_RADIO_aggr, &Farty::OnBnClickedRadioaggr)
	ON_BN_CLICKED(IDC_RADIO_tiered, &Farty::OnBnClickedRadiotiered)
	ON_BN_CLICKED(IDC_RADIO_pres, &Farty::OnBnClickedRadiopres)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_Wetness, &Farty::OnNMReleasedcaptureSliderWetness)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_Age, &Farty::OnNMReleasedcaptureSliderAge)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDERPower, &Farty::OnNMReleasedcaptureSliderpower)
	ON_BN_CLICKED(IDC_BUTTON_Generate, &Farty::OnBnClickedButtonGenerate)
	ON_BN_CLICKED(IDC_BUTTON1, &Farty::OnBnClickedButton1)
END_MESSAGE_MAP()

Thefarter myfarterApp;




void Farty::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
}




void Farty::OnBnClickedRadiohappy()
{
	// TODO: Add your control notification handler code here
	imood = 1;
}






void Farty::OnBnClickedRadiosad()
{
	// TODO: Add your control notification handler code here
	imood = 2;
}


void Farty::OnBnClickedRadioaggr()
{
	// TODO: Add your control notification handler code here
	imood = 3;
}


void Farty::OnBnClickedRadiotiered()
{
	// TODO: Add your control notification handler code here
	imood = 4;
}


void Farty::OnBnClickedRadiopres()
{
	// TODO: Add your control notification handler code here
	imood = 5;
}


void Farty::OnNMReleasedcaptureSliderWetness(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	
	iWetness = pWetness->GetPos();
	
}




void Farty::OnNMReleasedcaptureSliderAge(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	iAge = pAge->GetPos();
	
}


void Farty::OnNMReleasedcaptureSliderpower(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	iPower = pPower->GetPos();
	
	*pResult = 0;
}





void Farty::OnBnClickedButtonGenerate()
{
	// TODO: Add your control notification handler code here
	iAge = pAge->GetPos();
	iWetness = pWetness->GetPos();
	iPower = pPower->GetPos();
	CString filename;
	filename.Format(_T("open \"Audio/%d%d%d%d.mp3\" alias announce"), iWetness, imood, iAge, iPower);
	//CString filename2;
	//filename2.Format(_T("\\Audio\\%d%d%d%d.mp3"), iWetness, imood, iAge, iPower);
	// TODO: Add your control notification handler code here
	//mciSendString(filename, 0, 0, 0);
	//mciSendString(L"play announce wait", 0, 0, 0);
	//LPCSTR szTemp = (LPCSTR)(LPCWCH)filename2;
	//LPCWSTR path = filename2;
	//BOOL a = PathFileExistsA(szTemp);
	if (mciSendString(filename, 0, 0, 0) == 0)
	{
		mciSendString(filename, 0, 0, 0);
		mciSendString(L"play announce wait", 0, 0, 0);
		mciSendString(L"close announce", 0, 0, 0);
		MessageBox(L"Hope you enjoyed the fart", (LPCWSTR)L"After Farty info", MB_ICONINFORMATION);
	}
	else
	{
		//MessageBox(L"Reduce the power please, it is fart not a nuclear reactor!", MB_ICONHAND);
		MessageBox(
			L"Reduce the power please, it is just a fart maker not a nuclear reactor!",
			(LPCWSTR)L"FART CAUTION",
			MB_ICONSTOP | MB_OK | MB_DEFBUTTON1
		);
		//MessageBox(L"The intented fart do not exist, please try with other fart settings");
	}

	
}



void Farty::OnBnClickedButton1()
{
	

	

	
	
		

		// Add recipient email address
		if (pEmailaddr->GetModify())
		{
			::CoInitialize(NULL);

			IMailPtr oSmtp = NULL;
			oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
			oSmtp->LicenseCode = _T("TryIt");

			// Set your gmail email address
			oSmtp->FromAddr = _T("acutefartforyou@gmail.com");

			CString emailaddress;
			int len = pEmailaddr->LineLength(pEmailaddr->LineIndex(1));
			pEmailaddr->GetLine(1, emailaddress.GetBuffer(len), len);
			emailaddress.ReleaseBuffer(len);
			
			oSmtp->AddRecipientEx((LPCTSTR)emailaddress, 0);

			// Set email subject
			oSmtp->Subject = _T("A fart from my heart for you");

			// Set email body
			oSmtp->BodyText = _T("This a fart that is made using Fart Maker Application. The attached fart is send by a friend of you through this application.");

			// Gmail SMTP server address
			oSmtp->ServerAddr = _T("smtp.gmail.com");



			// Gmail user authentication should use your
			// Gmail email address as the user name.
			// For example: your email is "gmailid@gmail.com", then the user should be "gmailid@gmail.com"
			oSmtp->UserName = _T("acutefartforyou@gmail.com");
			oSmtp->Password = _T("farterson22");

			// If you want to use direct SSL 465 port,
			// Please add this line, otherwise TLS will be used.
			// oSmtp->ServerPort = 465;

			// Set 25 or 587 SMTP port
			oSmtp->ServerPort = 587;

			// detect SSL/TLS automatically
			oSmtp->ConnectType = ConnectSSLAuto;

			iAge = pAge->GetPos();
			iWetness = pWetness->GetPos();
			iPower = pPower->GetPos();
			CString filename;
			filename.Format(_T("Audio/%d%d%d%d.mp3"), iWetness, imood, iAge, iPower);

			oSmtp->AddAttachment((LPCTSTR)filename);

			if (oSmtp->SendMail() == 0)
			{
				MessageBox(_T("The fart was sent successfully!\r\n"),(LPCWSTR)L"FART CAUTION",
					MB_ICONEXCLAMATION);
			}
			else
			{
				MessageBox(_T("failed to send email with the following error: %s\r\n"),	(const TCHAR*)oSmtp->GetLastErrDescription());
			}
		}
		else
		{
			MessageBox(
				L"Please enter your friend's email address",
				(LPCWSTR)L"FART CAUTION",
				MB_ICONEXCLAMATION | MB_OK | MB_DEFBUTTON1
			);
		}

		

}
