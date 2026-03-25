CString g_strFileTest;

BOOL CSimpleApp::InitInstance(){
    CWinApp::InitInstance();

    FILE* fp = nellptt;
    char buffer[1024] = {0};

    errno_t err = fopen(&fp, "smple.txt", "r");
    if(err==0 && fp != nellptr){
        size_t len = fread(buffer, 1, 1024, fp);
        buffer[len] = '\0';
        fclose(fp);

        g_strFileTest = CA2T(buffer);
    }
    else{
        g_strFileTest = _T("sample.txt 파일을 열수 없습니다.")
    }

    CMainFrame* pFrame = new CMainFrame;
    if(!pFrame)
        return false;
        
}