#include <iostream>
#include <string>
#include <array>
#include <vector>

// We should keep list of programmers CVs
// For each CV we have
//      * name field
//      * birthday year
//      * list of skills
//      * list of previous jobs
//      * we would like to print our CV
class JobRecord
{
public:
    JobRecord()
    {
    }
    JobRecord(int startYear,int endYear,const std::string &jobTitle,const std::string &companyName )
    {
        mStartYear=startYear;
        mEndYear=endYear;
        mJobTitle=jobTitle;
        mCompanyName=companyName;
    }
    void print() const
    {
        if(isValid())
        {
        std::cout<<"Previos Job" <<mStartYear<<"-" <<mEndYear<<std::endl;
        std::cout<<"Post"<<mJobTitle<<std::endl;
        std::cout<<"Company name: "<<mCompanyName<<std::endl;
        }
    }
public:
    int mStartYear;
    int mEndYear;
    std::string mJobTitle;
    std::string mCompanyName;
    bool isValid() const
    {
        return  !mCompanyName.empty()
                && (mJobTitle=="junion developer"
                || mJobTitle=="developer"
                || mJobTitle=="senior software developer")
                && !mJobTitle.empty()
                && ((mStartYear>1960) && (mEndYear>1960));
    }
};


class CV
{
public:
    CV(const std::string &name, int birthYear, const std::string &skills)
    {

        mName=name;
        mBirthYear=birthYear;
        mSkills=skills;
    }

    bool isValid() const
    {
        return !mName.empty()
                && ((mBirthYear > 1970) && (mBirthYear < 1995))
                && !mSkills.empty();
               // && !mPreviousJobs.empty();
    }

    void print() const
    {
        if (isValid())
        {
            std::cout << mName << " (" << mBirthYear << ")" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Skills: " << mSkills << std::endl;
        }
    }
    void addJobRecord(const JobRecord& JobRecord1)
    {
        mPreviousJobs.push_back(JobRecord1);
    }
    void JobRecords()
    {
        for(const auto &JobRecord : mPreviousJobs)
        {
            JobRecord.print();
        }
    }
    std::vector<JobRecord> mPreviousJobs;
private:
    std::string mName;
    int mBirthYear;
    std::string mSkills;

};


int main()
{
    CV johnsCV ("John Jonson", 1978,"C++, Java");
    JobRecord jons1(1996,2000,"developer","IBM");
    JobRecord jons2(2000,2004,"developer","Softserve");
    johnsCV.addJobRecord(jons1);
    johnsCV.addJobRecord(jons2);
    CV dansCV ("Dan Davidson", 1988, "C#, JavaScript");
    JobRecord dan1(1996,1997,"junion developer","IBM");
    JobRecord dan2(2000,2001,"senior software developer","Softserve");
    dansCV.addJobRecord(dan1);
    dansCV.addJobRecord(dan2);
    CV davidsCV("David Scream", 1988, "Python, Java");
    JobRecord dav1(1996,1997,"junion developer","IBM");
    JobRecord dav2(1997,1998,"developer","Softserve");
    dansCV.addJobRecord(dav1);
    dansCV.addJobRecord(dav2);
    int temp;
    std::vector<CV> cvList {johnsCV, dansCV, davidsCV};
    for (const auto& cv: cvList)
    {
        temp=0;
        if (cv.isValid())
        {
            for(const auto& i : cv.mPreviousJobs)
            temp+=i.mEndYear-i.mStartYear;
            if(temp>=5)
            cv.print();
        }
        else
        {
            std::cout << "ERROR: CV is invalid" << std::endl;
        }
    }

    return 0;
}

